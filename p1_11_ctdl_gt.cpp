#include <iostream>
using namespace std;

// Cấu trúc node
struct node
{
    int val;
    int dem; // Đếm số lần xuất hiện của phần tử
    node *pNext;

    node(int n) : val(n), dem(1), pNext(nullptr) {}; // Khởi tạo giá trị và đếm
};

struct List
{
    node *pHead;
    node *pTail;

    List() : pHead(nullptr), pTail(nullptr) {}; // Khởi tạo danh sách rỗng
};

void inserttree(List &l, int n)
{
    if (l.pHead == nullptr)
    {
        l.pHead = new node(n); // Nếu danh sách rỗng, tạo phần tử đầu tiên
        l.pTail = l.pHead;
        return;
    }
    node *tmp = new node(n); // Tạo nút mới
    l.pTail->pNext = tmp;    // Liên kết nút mới vào cuối danh sách
    l.pTail = tmp;           // Cập nhật phần tử cuối
}

void print(List l, int max)
{
    if (l.pHead == nullptr)
    {
        return;
    }
    node *cur = l.pHead;
    while (cur != nullptr)
    {
        if (cur->dem == max)
        {
            cout << cur->val << ": " << cur->dem << endl; // In giá trị và số lần xuất hiện
        }
        cur = cur->pNext;
    }
}

void dem(List &l)
{
    if (l.pHead == nullptr)
    {
        return;
    }

    node *cur = l.pHead;
    while (cur != nullptr)
    {
        node *next = cur->pNext;
        node *prev = cur;

        while (next != nullptr)
        {
            if (next->val == cur->val)
            {                              // Nếu phần tử trùng lặp
                cur->dem++;                // Tăng số lần xuất hiện
                prev->pNext = next->pNext; // Xóa phần tử trùng lặp
                node *tmp = next;
                next = next->pNext;
                delete tmp; // Giải phóng bộ nhớ phần tử bị xóa
            }
            else
            {
                prev = next;
                next = next->pNext;
            }
        }
        cur = cur->pNext; // Tiến đến phần tử tiếp theo
    }
}

void reverse(List &l)
{
    if (l.pHead == nullptr)
    {
        return;
    }
    node *prev = nullptr;
    node *cur = l.pHead;
    node *next = nullptr;

    while (cur != nullptr)
    {
        next = cur->pNext;
        cur->pNext = prev;
        prev = cur;
        cur = next;
    }
    l.pHead = prev;
}

int findmax(List l)
{
    node *cur = l.pHead;
    int max = cur->dem;
    cur = cur->pNext;
    while (cur != nullptr)
    {
        if (cur->dem > max)
        {
            max = cur->dem;
        }
        cur = cur->pNext;
    }
    return max;
}

void printlist(List l)
{
    if (l.pHead == nullptr)
    {
        return;
    }
    node *cur = l.pHead;
    while (cur != nullptr)
    {
        cout << cur->val << " ";
        cur = cur->pNext;
    }
    cout << endl;
}
int main()
{
    List l;

    // Nhập vào danh sách
    while (true)
    {
        int n;
        cin >> n;
        if (n != 0)
        {
            inserttree(l, n); // Thêm phần tử vào danh sách
        }
        else
        {
            break; // Dừng nhập khi nhập 0
        }
    }

    if (l.pHead == nullptr)
    {
        cout << "Danh sach rong." << endl;
        return 0;
    }
    else
    {
        reverse(l);
        printlist(l);
        dem(l);
        int max = findmax(l);
        print(l, max);
    }

    return 0;
}
