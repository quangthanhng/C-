#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int value) : data(value), left(NULL), right(NULL) {}
};

struct Tree {
    Node *root;
    Tree() : root(NULL) {}

    // Hàm thêm phần tử vào cây
    Node *_insert(Node *node, int value) {
        if (node == NULL) {
            return new Node(value);
        }
        if (value <= node->data) {
            node->left = _insert(node->left, value);
        } else {
            node->right = _insert(node->right, value);
        }
        return node;
    }

    void insert(int value) {
        root = _insert(root, value);
    }

    // Hàm tìm lá lớn nhất
    int find_max(Node *node) {
        if (node == NULL) return -1; // Trường hợp cây rỗng
        while (node->right != NULL) {
            node = node->right;
        }
        return node->data;
    }

    // Hàm xóa lá lớn nhất
    Node *_delete_max(Node *node, int &max_value) {
        if (node == NULL) return NULL;
        if (node->right == NULL) {
            max_value = node->data; // Ghi nhận giá trị lớn nhất
            Node *temp = node->left; // Cập nhật cây con trái
            delete node;
            return temp;
        }
        node->right = _delete_max(node->right, max_value);
        return node;
    }

    void delete_max() {
        if (root == NULL) {
            cout << "NULL" << endl;
        } else {
            int max_value;
            root = _delete_max(root, max_value);
            cout << max_value << endl;
        }
    }
};

int main() {
    Tree tree;
    char command;
    int value;

    while (true) {
        cin >> command;
        if (command == 'E') {
            break;
        }
        if (command == 'U') {
            cin >> value;
            tree.insert(value);
        } else if (command == 'O') {
            tree.delete_max();
        }
    }
    return 0;
}
