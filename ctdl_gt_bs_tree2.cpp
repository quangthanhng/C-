#include <iostream>
using namespace std;

struct Node {
    double key;
    Node* left;
    Node* right;
    Node(double k) : key(k), left(nullptr), right(nullptr) {}
};

Node* insert(Node* node, double key, int& count, double& sum) {
    if (!node) {
        count++;
        sum += key;
        return new Node(key);
    }
    if (key < node->key) {
        node->left = insert(node->left, key, count, sum);
    } else {
        node->right = insert(node->right, key, count, sum);
    }
    return node;
}

bool contains(Node* node, double key) {
    if (!node) return false;
    if (node->key == key) return true;
    if (key < node->key) return contains(node->left, key);
    return contains(node->right, key);
}

void inOrderTraversal(Node* node) {
    if (node) {
        inOrderTraversal(node->left);
        cout << node->key << " ";
        inOrderTraversal(node->right);
    }
}

int main() {
    int n;
    cin >> n;
    Node* root = nullptr;
    int count = 0;
    double sum = 0;

    for (int i = 0; i < n; ++i) {
        double key;
        cin >> key;
        root = insert(root, key, count, sum);
    }

    double avg = count ? sum / count : 0;
    if (contains(root, avg)) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

    inOrderTraversal(root);
    cout << endl;
    return 0;
}