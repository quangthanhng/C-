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

    // Hàm đệ quy để tìm các phần tử tại mỗi mức
    void printLevels(Node* node, int level) {
        if (node == NULL) return;

        // In ra các phần tử ở mức hiện tại
        if (level == 1) {
            cout << node->data << " ";
        } else if (level > 1) {
            printLevels(node->left, level - 1);
            printLevels(node->right, level - 1);
        }
    }

    // Hàm in tất cả các mức của cây
    void printAllLevels() {
        if (root == NULL) {
            cout << "Danh sach rong." << endl;
            return;
        }

        int height = treeHeight(root);
        for (int level = 1; level <= height; level++) {
            cout << "Deep " << level << ": ";
            printLevels(root, level);
            cout << endl;
        }
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
    
    while (true) {
        cin >> n;
        if (n == 0) break;  // Kết thúc khi nhập 0
        tree.insert(n);
    }

    // In ra các phần tử ở mỗi mức của cây BST
    tree.printAllLevels();

    return 0;
}