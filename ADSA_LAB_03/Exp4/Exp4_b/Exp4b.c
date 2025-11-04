#include <stdio.h>
#include <stdlib.h>

#define T 3   // Minimum degree (can change this)

typedef struct BTreeNode {
    int keys[2 * T - 1];
    struct BTreeNode *child[2 * T];
    int n;
    int leaf;
} BTreeNode;

// Function prototypes
BTreeNode* createNode(int leaf);
void traverse(BTreeNode *root);
BTreeNode* search(BTreeNode *root, int key);
void insert(BTreeNode **root, int key);
void deleteKey(BTreeNode **root, int key);

// ----------------------- CREATE NODE -----------------------
BTreeNode* createNode(int leaf) {
    BTreeNode *node = (BTreeNode*)malloc(sizeof(BTreeNode));
    node->leaf = leaf;
    node->n = 0;
    for (int i = 0; i < 2 * T; i++)
        node->child[i] = NULL;
    return node;
}

// ----------------------- TRAVERSAL -----------------------
void traverse(BTreeNode *root) {
    if (root == NULL) return;
    int i;
    for (i = 0; i < root->n; i++) {
        if (!root->leaf)
            traverse(root->child[i]);
        printf("%d ", root->keys[i]);
    }
    if (!root->leaf)
        traverse(root->child[i]);
}

// ----------------------- SEARCH -----------------------
BTreeNode* search(BTreeNode *root, int key) {
    int i = 0;
    while (i < root->n && key > root->keys[i])
        i++;

    if (i < root->n && root->keys[i] == key)
        return root;

    if (root->leaf)
        return NULL;

    return search(root->child[i], key);
}

// ----------------------- SPLIT CHILD -----------------------
void splitChild(BTreeNode *parent, int i, BTreeNode *y) {
    BTreeNode *z = createNode(y->leaf);
    z->n = T - 1;

    for (int j = 0; j < T - 1; j++)
        z->keys[j] = y->keys[j + T];

    if (!y->leaf) {
        for (int j = 0; j < T; j++)
            z->child[j] = y->child[j + T];
    }

    y->n = T - 1;

    for (int j = parent->n; j >= i + 1; j--)
        parent->child[j + 1] = parent->child[j];
    parent->child[i + 1] = z;

    for (int j = parent->n - 1; j >= i; j--)
        parent->keys[j + 1] = parent->keys[j];
    parent->keys[i] = y->keys[T - 1];
    parent->n++;
}

// ----------------------- INSERT NON-FULL -----------------------
void insertNonFull(BTreeNode *x, int k) {
    int i = x->n - 1;

    if (x->leaf) {
        while (i >= 0 && x->keys[i] > k) {
            x->keys[i + 1] = x->keys[i];
            i--;
        }
        x->keys[i + 1] = k;
        x->n++;
    } else {
        while (i >= 0 && x->keys[i] > k)
            i--;

        if (x->child[i + 1]->n == 2 * T - 1) {
            splitChild(x, i + 1, x->child[i + 1]);
            if (k > x->keys[i + 1])
                i++;
        }
        insertNonFull(x->child[i + 1], k);
    }
}

// ----------------------- INSERT -----------------------
void insert(BTreeNode **root, int k) {
    BTreeNode *r = *root;
    if (r->n == 2 * T - 1) {
        BTreeNode *s = createNode(0);
        s->child[0] = r;
        splitChild(s, 0, r);

        int i = 0;
        if (s->keys[0] < k)
            i++;
        insertNonFull(s->child[i], k);
        *root = s;
    } else {
        insertNonFull(r, k);
    }
}

// ----------------------- DELETE HELPERS -----------------------
int getPred(BTreeNode *x, int idx) {
    BTreeNode *cur = x->child[idx];
    while (!cur->leaf)
        cur = cur->child[cur->n];
    return cur->keys[cur->n - 1];
}

int getSucc(BTreeNode *x, int idx) {
    BTreeNode *cur = x->child[idx + 1];
    while (!cur->leaf)
        cur = cur->child[0];
    return cur->keys[0];
}

void merge(BTreeNode *x, int idx) {
    BTreeNode *child = x->child[idx];
    BTreeNode *sibling = x->child[idx + 1];

    child->keys[T - 1] = x->keys[idx];
    for (int i = 0; i < sibling->n; i++)
        child->keys[i + T] = sibling->keys[i];

    if (!child->leaf) {
        for (int i = 0; i <= sibling->n; i++)
            child->child[i + T] = sibling->child[i];
    }

    for (int i = idx + 1; i < x->n; i++)
        x->keys[i - 1] = x->keys[i];
    for (int i = idx + 2; i <= x->n; i++)
        x->child[i - 1] = x->child[i];

    child->n += sibling->n + 1;
    x->n--;

    free(sibling);
}

void borrowFromPrev(BTreeNode *x, int idx) {
    BTreeNode *child = x->child[idx];
    BTreeNode *sibling = x->child[idx - 1];

    for (int i = child->n - 1; i >= 0; i--)
        child->keys[i + 1] = child->keys[i];

    if (!child->leaf) {
        for (int i = child->n; i >= 0; i--)
            child->child[i + 1] = child->child[i];
    }

    child->keys[0] = x->keys[idx - 1];
    if (!child->leaf)
        child->child[0] = sibling->child[sibling->n];

    x->keys[idx - 1] = sibling->keys[sibling->n - 1];
    child->n++;
    sibling->n--;
}

void borrowFromNext(BTreeNode *x, int idx) {
    BTreeNode *child = x->child[idx];
    BTreeNode *sibling = x->child[idx + 1];

    child->keys[child->n] = x->keys[idx];
    if (!child->leaf)
        child->child[child->n + 1] = sibling->child[0];

    x->keys[idx] = sibling->keys[0];

    for (int i = 1; i < sibling->n; i++)
        sibling->keys[i - 1] = sibling->keys[i];

    if (!sibling->leaf) {
        for (int i = 1; i <= sibling->n; i++)
            sibling->child[i - 1] = sibling->child[i];
    }

    child->n++;
    sibling->n--;
}

void fill(BTreeNode *x, int idx) {
    if (idx != 0 && x->child[idx - 1]->n >= T)
        borrowFromPrev(x, idx);
    else if (idx != x->n && x->child[idx + 1]->n >= T)
        borrowFromNext(x, idx);
    else {
        if (idx != x->n)
            merge(x, idx);
        else
            merge(x, idx - 1);
    }
}

// ----------------------- DELETE FROM NODE -----------------------
void deleteFromNode(BTreeNode *x, int k);

void deleteKey(BTreeNode **root, int k) {
    if (*root == NULL) {
        printf("Tree is empty.\n");
        return;
    }

    deleteFromNode(*root, k);

    if ((*root)->n == 0) {
        BTreeNode *tmp = *root;
        if ((*root)->leaf)
            *root = NULL;
        else
            *root = (*root)->child[0];
        free(tmp);
    }
}

void deleteFromNode(BTreeNode *x, int k) {
    int idx = 0;
    while (idx < x->n && x->keys[idx] < k)
        idx++;

    if (idx < x->n && x->keys[idx] == k) {
        if (x->leaf) {
            for (int i = idx + 1; i < x->n; i++)
                x->keys[i - 1] = x->keys[i];
            x->n--;
        } else {
            if (x->child[idx]->n >= T) {
                int pred = getPred(x, idx);
                x->keys[idx] = pred;
                deleteFromNode(x->child[idx], pred);
            } else if (x->child[idx + 1]->n >= T) {
                int succ = getSucc(x, idx);
                x->keys[idx] = succ;
                deleteFromNode(x->child[idx + 1], succ);
            } else {
                merge(x, idx);
                deleteFromNode(x->child[idx], k);
            }
        }
    } else {
        if (x->leaf) {
            printf("The key %d is not present.\n", k);
            return;
        }

        int flag = (idx == x->n);
        if (x->child[idx]->n < T)
            fill(x, idx);

        if (flag && idx > x->n)
            deleteFromNode(x->child[idx - 1], k);
        else
            deleteFromNode(x->child[idx], k);
    }
}

// ----------------------- MAIN FUNCTION -----------------------
int main() {
    BTreeNode *root = createNode(1);
    int choice, val;

    while (1) {
        printf("\n\n--- B-TREE MENU ---\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Search\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insert(&root, val);
                printf("Inserted %d\n", val);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                deleteKey(&root, val);
                printf("Deleted %d\n", val);
                break;

            case 3:
                printf("B-Tree contents: ");
                traverse(root);
                printf("\n");
                break;

            case 4:
                printf("Enter value to search: ");
                scanf("%d", &val);
                if (search(root, val))
                    printf("%d found in B-Tree.\n", val);
                else
                    printf("%d not found.\n", val);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
