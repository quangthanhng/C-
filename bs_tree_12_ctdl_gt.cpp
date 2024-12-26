#include <iostream>
using namespace std;

struct node {
    int data;
    node *left;
    node *right;
};

void inDanhSachGiamDan(node *TREE);
string chuyenNhiPhan(int x);
bool kiemTraDoiXung(string s);
void demSoChuoiDoiXung(node *TREE, int &cnt);
node *themPhanTuVaoCay(node *&root, int x);

int main() {
    node *TREE = NULL;
    int x, cnt = 0;

    // Nhập và xử lý dữ liệu
    while (cin >> x) {
        if (x == 0) {
            inDanhSachGiamDan(TREE);
            cout << endl;
            demSoChuoiDoiXung(TREE, cnt);
            cout << "Co " << cnt << " node thoa de bai." << endl;
            break;
        } else {
            themPhanTuVaoCay(TREE, x);
        }
    }
    return 0;
}

node *themPhanTuVaoCay(node *&root, int x) {
    if (root == NULL) {
        node *temp = new node;
        temp->data = x;
        temp->left = temp->right = NULL;
        root = temp;
        return root;
    }
    if (x < root->data) {
        root->left = themPhanTuVaoCay(root->left, x);
    } else if (x >= root->data) {
        root->right = themPhanTuVaoCay(root->right, x);
    }
    return root;
}

void inDanhSachGiamDan(node *TREE) {
    if (TREE == NULL) {
        return;
    }
    inDanhSachGiamDan(TREE->right);
    cout << TREE->data << " ";
    inDanhSachGiamDan(TREE->left);
}

void demSoChuoiDoiXung(node *TREE, int &cnt) {
    if (TREE == NULL) {
        return;
    }
    string s = chuyenNhiPhan(TREE->data);
    if (kiemTraDoiXung(s)) {
        cnt++;
    }
    demSoChuoiDoiXung(TREE->left, cnt);
    demSoChuoiDoiXung(TREE->right, cnt);
}

string chuyenNhiPhan(int x) {
    string s = "";
    while (x > 0) {
        s = char((x % 2) + '0') + s; // Thêm bit nhị phân vào đầu chuỗi
        x /= 2;
    }
    return s;
}

bool kiemTraDoiXung(string s) {
    int n = s.size();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1]) {
            return false;
        }
    }
    return true;
}
