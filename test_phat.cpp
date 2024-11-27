#include <iostream>
#include <queue>
#include <cmath>
#include <cstdlib>
using namespace std;

struct node {
    int key;
    node* pleft;
    node* pright;
};

// Hàm tạo một node mới
node* createnode(int data) {
    node* p = new node();
    if (p == NULL) exit(1);
    p->key = data;
    p->pleft = NULL;
    p->pright = NULL;
    return p;
}

// Hàm chèn một node vào cây theo thứ tự duyệt theo mức
node* insertnode(node* root, int data) {
    if (root == NULL) {
        root = createnode(data);
        return root;
    }
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        node* tmp = q.front();
        q.pop();
        if (tmp->pleft != NULL) {
            q.push(tmp->pleft);
        }
        else {
            tmp->pleft = createnode(data);
            return root;
        }
        if (tmp->pright != NULL) {
            q.push(tmp->pright);
        }
        else {
            tmp->pright = createnode(data);
            return root;
        }
    }
    return root;
}

// Hàm kiểm tra nếu cây là cây đầy đủ
bool isfulltree(node* root) {
    if (root == NULL) return true;
    if (root->pleft == NULL && root->pright == NULL) return true;
    if (root->pleft && root->pright) {
        return (isfulltree(root->pleft) && isfulltree(root->pright));
    }
    return false;
}

// Hàm tìm node sâu nhất trong cây
node* deepestnode(node* root) {
    if (root == NULL) return NULL;
    queue<node*> q;
    q.push(root);
    node* temp = nullptr;
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        if (temp->pleft) q.push(temp->pleft);
        if (temp->pright) q.push(temp->pright);
    }
    return temp;
}

// Hàm xóa node sâu nhất và phải nhất
void deleteDeepestRightmostNode(node* root, node* d_node) {
    if (root == NULL) return;
    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        if (temp->pleft) {
            if (temp->pleft == d_node) {
                temp->pleft = NULL;
                delete d_node;
                return;
            } else {
                q.push(temp->pleft);
            }
        }

        if (temp->pright) {
            if (temp->pright == d_node) {
                temp->pright = NULL;
                delete d_node;
                return;
            } else {
                q.push(temp->pright);
            }
        }
    }
}

// Hàm xóa một node có giá trị cụ thể trong cây
node* deleteNode(node* root, int key) {
    if (root == NULL) return NULL;

    if (root->pleft == NULL && root->pright == NULL) {
        if (root->key == key) {
            delete root;
            return NULL;
        } else {
            return root;
        }
    }

    queue<node*> q;
    q.push(root);
    node* key_node = NULL;
    node* temp;

    while (!q.empty()) {
        temp = q.front();
        q.pop();

        if (temp->key == key) key_node = temp;

        if (temp->pleft) q.push(temp->pleft);
        if (temp->pright) q.push(temp->pright);
    }

    if (key_node) {
        node* deepest_node = deepestnode(root);
        key_node->key = deepest_node->key;
        deleteDeepestRightmostNode(root, deepest_node);
    }

    return root;
}

// Hàm chèn ngẫu nhiên một node vào cây tới độ sâu tối đa maxLevel
void insertRandom(node*& root, int maxLevel) {
    int value = rand() % 100;
    if (root == nullptr) {
        root = createnode(value);
        return;
    }

    queue<pair<node*, int>> q;
    q.push({root, 1});

    while (!q.empty()) {
        node* curr = q.front().first;
        int level = q.front().second;
        q.pop();

        if (level < maxLevel) {
            if (curr->pleft == nullptr && rand() % 2) {
                curr->pleft = createnode(rand() % 100);
                return;
            } else if (curr->pleft) {
                q.push({curr->pleft, level + 1});
            }

            if (curr->pright == nullptr && rand() % 2) {
                curr->pright = createnode(rand() % 100);
                return;
            } else if (curr->pright) {
                q.push({curr->pright, level + 1});
            }
        }
    }
}

// Hàm in cây với cấu trúc đầy đủ, các node trống hiển thị dưới dạng "[]"
void printTree(node* root, int maxLevel) {
    if (root == nullptr) {
        cout << "Tree is empty!" << endl;
        return;
    }

    queue<node*> q;
    q.push(root);
    int currentLevel = 1;

    while (!q.empty() && currentLevel <= maxLevel) {
        int levelNodes = pow(2, currentLevel - 1);
        int count = 0;

        cout << string((pow(2, maxLevel - currentLevel) - 1) * 3, ' ');

        for (int i = 0; i < levelNodes; i++) {
            node* curr = q.empty() ? nullptr : q.front();
            if (!q.empty()) q.pop();

            if (curr) {
                cout << curr->key;
                q.push(curr->pleft);
                q.push(curr->pright);
            } else {
                cout << " []";
                q.push(nullptr);
                q.push(nullptr);
            }

            count++;
            if (count < levelNodes) {
                cout << string((pow(2, maxLevel - currentLevel + 1) - 1) * 3, ' ');
            }
        }

        cout << endl;
        currentLevel++;
    }
}

int main() {
    srand(time(0));
    node* root = nullptr;

    int maxLevel;
    cout << "Enter the maximum depth of the tree: ";
    cin >> maxLevel;

    for (int i = 0; i < 10; i++) {
        insertRandom(root, maxLevel);
    }

    cout << "Tree representation with missing nodes as [ ]:" << endl;
    printTree(root, maxLevel);
    cout<<"Insert node with key: ";
    int x; cin>>x;
    root=insertnode(root,x);
    printTree(root, maxLevel);

    return 0;
}