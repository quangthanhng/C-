#include <iostream>
#include <vector>
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

int countLeafNodes(Node* node) {
    if (!node) return 0;
    if (!node->left && !node->right) return 1;
    return countLeafNodes(node->left) + countLeafNodes(node->right);
}

void collectLeafNodes(Node* node, vector<double>& leaves) {
    if (!node) return;
    if (!node->left && !node->right) {
        leaves.push_back(node->key);
    }
    collectLeafNodes(node->left, leaves);
    collectLeafNodes(node->right, leaves);
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

    int leafCount = countLeafNodes(root);
    vector<double> leafNodes;
    collectLeafNodes(root, leafNodes);

    cout << leafCount << endl;
    for (double key : leafNodes) {
        cout << key << " ";
    }
    cout << endl;

    return 0;
}