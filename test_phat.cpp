#include <iostream>
#include <queue>
using namespace std;

// Định nghĩa cấu trúc Node
struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int value) {
        key = value;
        left = nullptr;
        right = nullptr;
    }
};

// Duyệt cây theo In-order (Left-Root-Right)
void inOrder(Node* root) {
    if (root == nullptr) return;
    inOrder(root->left);
    cout << root->key << " ";
    inOrder(root->right);
}

bool isPerfectTree(Node* root){
    int left = 0;
    int right = 0;
    while(root->left != NULL){
        root = root->left;
        left++;
    }
    while(root->right != NULL){
        root = root->right;
        right++;
    }
    if(right != left){
        return false;
    }
    else return true;
}

// Duyệt cây theo Pre-order (Root-Left-Right)
void preOrder(Node* root) {
    if (root == nullptr) return;
    cout << root->key << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// Duyệt cây theo Post-order (Left-Right-Root)
void postOrder(Node* root) {
    if (root == nullptr) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->key << " ";
}

// Duyệt cây theo Level-order
void levelOrder(Node* root) {
    if (root == nullptr) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->key << " ";
        if (current->left != nullptr) q.push(current->left);
        if (current->right != nullptr) q.push(current->right);
    }
}

// Hàm chính
int main() {
    // Tạo cây nhị phân
    Node* root = new Node(3);
    root->left = new Node(11);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(9);
    root->right->left = new Node(8);
    root->right->right = new Node(7);
    root->left->left->left = new Node(4);
    root->left->left->right = new Node(10);
    root->right->left->left = new Node(2);
    root->right->left->right = new Node(6);

    // In kết quả duyệt cây
    cout << "In-order (Left-Root-Right): ";
    inOrder(root);
    cout << endl;

    cout << "Pre-order (Root-Left-Right): ";
    preOrder(root);
    cout << endl;

    cout << "Post-order (Left-Right-Root): ";
    postOrder(root);
    cout << endl;

    cout << "Level-order: ";
    levelOrder(root);
    cout << endl;
    cout << (isPerfectTree(root) ? "Perfect tree" : "Not perfect tree");

    return 0;

}
