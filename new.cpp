#include <iostream>
#include <set>
using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;
    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;
    set<int> values; // To ensure distinct elements

    void insert(Node*& node, int val) {
        if (node == nullptr) {
            node = new Node(val);
        } else if (val < node->value) {
            insert(node->left, val);
        } else if (val > node->value) {
            insert(node->right, val);
        }
    }

    void inOrder(Node* node, int* result, int& index) {
        if (node != nullptr) {
            inOrder(node->left, result, index);
            result[index++] = node->value;
            inOrder(node->right, result, index);
        }
    }

    void postOrder(Node* node, int* result, int& index) {
        if (node != nullptr) {
            postOrder(node->left, result, index);
            postOrder(node->right, result, index);
            result[index++] = node->value;
        }
    }

    void reverseInOrder(Node* node, int* result, int& index) {
        if (node != nullptr) {
            reverseInOrder(node->right, result, index);
            result[index++] = node->value;
            reverseInOrder(node->left, result, index);
        }
    }

    void reversePostOrder(Node* node, int* result, int& index) {
        if (node != nullptr) {
            reversePostOrder(node->right, result, index);
            reversePostOrder(node->left, result, index);
            result[index++] = node->value;
        }
    }

    void preOrder(Node* node, int* result, int& index) {
        if (node != nullptr) {
            result[index++] = node->value;
            preOrder(node->left, result, index);
            preOrder(node->right, result, index);
        }
    }

    void reversePreOrder(Node* node, int* result, int& index) {
        if (node != nullptr) {
            result[index++] = node->value;
            reversePreOrder(node->right, result, index);
            reversePreOrder(node->left, result, index);
        }
    }

public:
    BST() : root(nullptr) {}

    void insert(int val) {
        if (values.find(val) == values.end()) {
            values.insert(val);
            insert(root, val);
        }
    }

    void getInOrder(int* result, int& index) {
        inOrder(root, result, index);
    }

    void getPostOrder(int* result, int& index) {
        postOrder(root, result, index);
    }

    void getReverseInOrder(int* result, int& index) {
        reverseInOrder(root, result, index);
    }

    void getReversePostOrder(int* result, int& index) {
        reversePostOrder(root, result, index);
    }

    void getPreOrder(int* result, int& index) {
        preOrder(root, result, index);
    }

    void getReversePreOrder(int* result, int& index) {
        reversePreOrder(root, result, index);
    }
};

int main() {
    BST tree;
    int val;
    while (cin >> val && val != 0) {
        tree.insert(val);
    }

    int result[100]; // Assuming the maximum number of nodes is 100
    int index = 0;

    cout << "LNR: ";
    tree.getInOrder(result, index);
    for (int i = 0; i < index; ++i) cout << result[i] << " ";
    cout << endl;

    index = 0;
    cout << "LRN: ";
    tree.getPostOrder(result, index);
    for (int i = 0; i < index; ++i) cout << result[i] << " ";
    cout << endl;

    index = 0;
    cout << "RNL: ";
    tree.getReverseInOrder(result, index);
    for (int i = 0; i < index; ++i) cout << result[i] << " ";
    cout << endl;

    index = 0;
    cout << "RLN: ";
    tree.getReversePostOrder(result, index);
    for (int i = 0; i < index; ++i) cout << result[i] << " ";
    cout << endl;

    index = 0;
    cout << "NLR: ";
    tree.getPreOrder(result, index);
    for (int i = 0; i < index; ++i) cout << result[i] << " ";
    cout << endl;

    index = 0;
    cout << "NRL: ";
    tree.getReversePreOrder(result, index);
    for (int i = 0; i < index; ++i) cout << result[i] << " ";
    cout << endl;

    return 0;
}