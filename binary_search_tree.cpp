#include <iostream>
#include <string>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int value) : data(value), left(NULL), right(NULL) {}
};

struct Tree
{
    Node *root;

    Tree(int value) : root(new Node(value)) {}

    void traverse_preorder(Node *node)
    {
        if (node == NULL)
            return;
        std::cout << node->data << " ";
        traverse_preorder(node->left);
        traverse_preorder(node->right);
    }

    void traverse_postorder(Node *node, int level = 0)
    {
        if (node == NULL)
            return;
        traverse_postorder(node->left);
        traverse_postorder(node->right);
        std::cout << node->data << " ";
    }

    void traverse_inorder(Node *node)
    {
        if (node == NULL)
            return;
        traverse_inorder(node->left);
        std::cout << node->data << " ";
        traverse_inorder(node->right);
    }

    void print()
    {
        traverse_inorder(root);
        std::cout << endl;
        traverse_postorder(root);
        std::cout << endl;
        traverse_preorder(root);
        std::cout << endl;
    }

    Node *_insert(Node *node, int value)
    {
        if (node == NULL)
            return new Node(value);
        if (value < node->data)
            node->left = _insert(node->left, value);
        else if (value > node->data)
            node->right = _insert(node->right, value);
        return node;
    }

    void insert(int value)
    {
        _insert(root, value);
    }

    Node *find_leftmost(Node *node)
    {
        while (node != NULL && node->left != NULL)
        {
            node = node->left; // Di chuyển xuống cây con trái
        }
        return node; // Trả về nút trái nhất
    }

    Node *_remove(Node *node, int value)
    {
        if (node == NULL)
            return NULL;

        if (value < node->data)
        {
            // Nếu giá trị cần xóa nhỏ hơn giá trị hiện tại, tìm bên trái
            node->left = _remove(node->left, value);
        }
        else if (value > node->data)
        {
            // Nếu giá trị cần xóa lớn hơn giá trị hiện tại, tìm bên phải
            node->right = _remove(node->right, value);
        }
        else
        {
            // Trường hợp tìm thấy nút cần xóa
            if (node->left == NULL)
            {
                // Nếu không có con trái, trả về cây con phải
                Node *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == NULL)
            {
                // Nếu không có con phải, trả về cây con trái
                Node *temp = node->left;
                delete node;
                return temp;
            }
            else
            {
                // Nếu có cả hai con
                // 1. Tìm nút trái nhất của cây con phải
                Node *leftmost = find_leftmost(node->right);

                // 2. Sao chép giá trị của nút trái nhất vào nút hiện tại
                node->data = leftmost->data;

                // 3. Xóa nút trái nhất trong cây con phải
                node->right = _remove(node->right, leftmost->data);
            }
        }
        return node;
    }

    void remove(int value)
    {
        _remove(root, value);
    }

    Node *_search(Node *node, int value)
    {
        if (node == NULL)
            return NULL;
        if (value == node->data)
        {
            return node;
        }
        else if (value < node->data)
        {
            return _search(node->left, value);
        }
        else
        {
            return _search(node->right, value);
        }
    }

    Node *search(int value)
    {
        return _search(root, value);
    }
    // Hàm tính chiều cao của cây
    int getHeight(struct Node *node)
    {
        if (node == nullptr)
            return 0;
        return 1 + std::max(getHeight(node->left), getHeight(node->right));
    }

    // Hàm kiểm tra xem cây có phải là cây nhị phân hoàn hảo hay không
    bool isPerfectTree(struct Node *root)
    {
        if (root == nullptr)
            return true;

        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        // Nếu chiều cao trái và phải không bằng nhau, cây không hoàn hảo
        if (leftHeight != rightHeight)
            return false;

        // Kiểm tra đệ quy các con của node
        return isPerfectTree(root->left) && isPerfectTree(root->right);
    }
};

int main()
{
    int n;
    cin >> n;
    Tree tree(n);
    while (true)
    {
        cin >> n;
        if (n == 0)
        {
            break;
        }
        tree.insert(n);
    }
    if (tree.root == NULL)
    {
        cout << "Danh sach rong. " << endl;
        return 0;
    }
    else
    {
        tree.print();
        cout << ((tree.isPerfectTree(tree.root)) ? "Perfect tree" : "Non-perfect tree"); 
    }

}