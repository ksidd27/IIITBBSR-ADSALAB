#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 256

// Huffman Tree Node
typedef struct Node {
    char data;
    unsigned freq;
    struct Node *left, *right;
} Node;

// Create a new node
Node* createNode(char data, unsigned freq) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

// Find smallest frequency node index
int findMin(Node* arr[], int size) {
    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i]->freq < arr[minIndex]->freq)
            minIndex = i;
    }
    return minIndex;
}

// Build Huffman Tree
Node* buildHuffmanTree(char data[], int freq[], int size) {
    Node* nodes[MAX_CHARS];
    for (int i = 0; i < size; i++)
        nodes[i] = createNode(data[i], freq[i]);

    while (size > 1) {
        int min1 = findMin(nodes, size);
        Node* left = nodes[min1];
        nodes[min1] = nodes[size - 1];
        size--;

        int min2 = findMin(nodes, size);
        Node* right = nodes[min2];
        nodes[min2] = nodes[size - 1];
        size--;

        Node* parent = createNode('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        nodes[size++] = parent;
    }

    return nodes[0];
}

// Store Huffman codes in a lookup table
void buildCodes(Node* root, char codes[MAX_CHARS][MAX_CHARS], int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        buildCodes(root->left, codes, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        buildCodes(root->right, codes, arr, top + 1);
    }
    if (!(root->left) && !(root->right)) {
        int i;
        for (i = 0; i < top; i++)
            codes[(unsigned char)root->data][i] = arr[i] + '0';
        codes[(unsigned char)root->data][i] = '\0';
    }
}

// Count frequencies of each character in text
int buildFrequency(const char* text, char data[], int freq[]) {
    int count[MAX_CHARS] = {0};

    for (int i = 0; text[i] != '\0'; i++)
        count[(unsigned char)text[i]]++;

    int size = 0;
    for (int i = 0; i < MAX_CHARS; i++) {
        if (count[i] > 0) {
            data[size] = i;
            freq[size] = count[i];
            size++;
        }
    }
    return size;
}

int main() {
    char text[1000];

    printf("Enter text (max 1000 chars): ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0;  // remove newline

    if (strlen(text) == 0) {
        printf("No input given. Exiting.\n");
        return 0;
    }

    char data[MAX_CHARS];
    int freq[MAX_CHARS];
    int size = buildFrequency(text, data, freq);

    Node* root = buildHuffmanTree(data, freq, size);

    char codes[MAX_CHARS][MAX_CHARS] = {{0}};
    int arr[MAX_CHARS], top = 0;
    buildCodes(root, codes, arr, top);

    printf("\nOriginal Message:\n%s\n", text);
    printf("\nHuffman Codes for each character:\n");
    for (int i = 0; i < size; i++) {
        if (data[i] == ' ')
            printf("'space': %s\n", codes[(unsigned char)data[i]]);
        else
            printf("'%c': %s\n", data[i], codes[(unsigned char)data[i]]);
    }

    // Encode the full text
    char encoded[10000] = "";
    for (int i = 0; text[i] != '\0'; i++)
        strcat(encoded, codes[(unsigned char)text[i]]);

    printf("\nFinal Encoded Message:\n%s\n", encoded);

    return 0;
}
