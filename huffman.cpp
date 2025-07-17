#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// A Tree node
struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

// Comparison function for min-heap (priority queue)
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Traverse the Huffman Tree and store the codes
void printCodes(Node* root, string code) {
    if (!root)
        return;

    // Found a leaf node
    if (!root->left && !root->right && root->ch != '#')
        cout << root->ch << ": " << code << endl;

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

int main() {
    // Example characters and their frequencies
    char chars[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] =    {  5,   9,  12, 13, 16, 45};
    int n = sizeof(chars) / sizeof(chars[0]);

    // Min-heap priority queue
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Step 1: Create leaf nodes and push to pq
    for (int i = 0; i < n; i++) {
        pq.push(new Node(chars[i], freq[i]));
    }

    // Step 2: Build the tree
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        // '#' is a dummy character for internal nodes
        Node* parent = new Node('#', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    // Root of Huffman Tree
    Node* root = pq.top();

    cout << "Huffman Codes:\n";
    printCodes(root, "");

    return 0;
}

