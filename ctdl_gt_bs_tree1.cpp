#include <iostream>
#include <set>
#include <vector>
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

    void inOrder(Node* node, vector<int>& result) {
        if (node != nullptr) {
            inOrder(node->left, result);
            result.push_back(node->value);
            inOrder(node->right, result);
        }
    }

    void postOrder(Node* node, vector<int>& result) {
        if (node != nullptr) {
            postOrder(node->left, result);
            postOrder(node->right, result);
            result.push_back(node->value);
        }
    }

    void reverseInOrder(Node* node, vector<int>& result) {
        if (node != nullptr) {
            reverseInOrder(node->right, result);
            result.push_back(node->value);
            reverseInOrder(node->left, result);
        }
    }

    void reversePostOrder(Node* node, vector<int>& result) {
        if (node != nullptr) {
            reversePostOrder(node->right, result);
            reversePostOrder(node->left, result);
            result.push_back(node->value);
        }
    }

    void preOrder(Node* node, vector<int>& result) {
        if (node != nullptr) {
            result.push_back(node->value);
            preOrder(node->left, result);
            preOrder(node->right, result);
        }
    }

    void reversePreOrder(Node* node, vector<int>& result) {
        if (node != nullptr) {
            result.push_back(node->value);
            reversePreOrder(node->right, result);
            reversePreOrder(node->left, result);
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

    vector<int> getInOrder() {
        vector<int> result;
        inOrder(root, result);
        return result;
    }

    vector<int> getPostOrder() {
        vector<int> result;
        postOrder(root, result);
        return result;
    }

    vector<int> getReverseInOrder() {
        vector<int> result;
        reverseInOrder(root, result);
        return result;
    }

    vector<int> getReversePostOrder() {
        vector<int> result;
        reversePostOrder(root, result);
        return result;
    }

    vector<int> getPreOrder() {
        vector<int> result;
        preOrder(root, result);
        return result;
    }

    vector<int> getReversePreOrder() {
        vector<int> result;
        reversePreOrder(root, result);
        return result;
    }
};

int main() {
    BST tree;
    int val;
    while (cin >> val && val != 0) {
        tree.insert(val);
    }

    vector<int> inOrder = tree.getInOrder();
    vector<int> postOrder = tree.getPostOrder();
    vector<int> reverseInOrder = tree.getReverseInOrder();
    vector<int> reversePostOrder = tree.getReversePostOrder();
    vector<int> preOrder = tree.getPreOrder();
    vector<int> reversePreOrder = tree.getReversePreOrder();

    cout << "LNR: ";
    for (int v : inOrder) cout << v << " ";
    cout << endl;

    cout << "LRN: ";
    for (int v : postOrder) cout << v << " ";
    cout << endl;

    cout << "RNL: ";
    for (int v : reverseInOrder) cout << v << " ";
    cout << endl;

    cout << "RLN: ";
    for (int v : reversePostOrder) cout << v << " ";
    cout << endl;

    cout << "NLR: ";
    for (int v : preOrder) cout << v << " ";
    cout << endl;

    cout << "NRL: ";
    for (int v : reversePreOrder) cout << v << " ";
    cout << endl;

    return 0;
}