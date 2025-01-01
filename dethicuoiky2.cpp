#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int value) : key(value), left(nullptr), right(nullptr) {}
};

Node* insert(Node* node, int key) {
    if (node == nullptr) return new Node(key);
    
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    
    return node;
}

int height(Node* node) {
    if (node == nullptr) return -1;  
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

void inorder(Node* node) {
    if (node == nullptr) return;
    inorder(node->left);
    cout << node->key << " ";
    inorder(node->right);
}

void findSatisfyingNodes(Node* node, int& maxLevel, int level, int& result) {
    if (node == nullptr) return;
    
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    
    if (rightHeight - leftHeight == 2) {
        if (level > maxLevel) {
            maxLevel = level;
            result = node->key;
        }
    }

    findSatisfyingNodes(node->left, maxLevel, level + 1, result);
    findSatisfyingNodes(node->right, maxLevel, level + 1, result);
}

int main() {
    Node* root = nullptr;
    int key;

    while (cin >> key && key != 0) {
        root = insert(root, key);
    }

    if (root == nullptr) {
        cout << "Empty tree" << endl;
        return 0;
    }

    inorder(root);
    cout << endl;

    int maxLevel = -1;  
    int result = -1;
    findSatisfyingNodes(root, maxLevel, 0, result);

    if (maxLevel == -1) {
        cout << "Not found!" << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}
