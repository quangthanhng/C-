#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(NULL), right(NULL) {}
};

struct Tree {
    Node* root;
    Tree() : root(NULL) {}

    Node* _insert(Node* node, int value) {
        if (node == NULL) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = _insert(node->left, value);
        } else if (value > node->data) {
            node->right = _insert(node->right, value);
        }
        return node;
    }

    void insert(int value) {
        root = _insert(root, value);
    }

    // Hàm tính chiều cao của cây
    int treeHeight(Node* node) {
        if (node == NULL) {
            return 0;
        }
        int leftHeight = treeHeight(node->left);
        int rightHeight = treeHeight(node->right);
        return max(leftHeight, rightHeight) + 1;
    }
};

int main() {
    Tree tree;
    int n;
    cin >> n;
    int a;
    for(int i = 0; i < n; i++){
        cin >> a;
        tree.insert(a);
    }
    cout << "Chieu cao cua cay la: " << tree.treeHeight(tree.root);

    return 0;
}
