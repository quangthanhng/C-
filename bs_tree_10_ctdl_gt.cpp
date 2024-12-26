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
    int length;
    Tree() : root(NULL), length(0) {}

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

    void node_grade_1(Node* node){
        if(node == NULL)
        return;
        else{
            node_grade_1(node->left);
            node_grade_1(node->right);
            if((node->left == NULL && node->right != NULL) || (node->left != NULL && node->right == NULL)){
                length++;
            } 
        }
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
    if(tree.root == NULL){
        cout << "Danh sach rong.";
        return 0;
    }else {
        tree.node_grade_1(tree.root);
        cout << "So node bac 1 cua cay la: " << tree.length;
    }

    return 0;
}
