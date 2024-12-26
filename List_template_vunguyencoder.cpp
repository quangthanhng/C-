#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int value) : data(value), next(NULL) {};
};

struct List
{
    Node *head;
    Node *tail;
    int length;

    List() : head(NULL), tail(NULL), length(0) {};
    ~List() {};

    void print_all()
    {
        if (head == NULL)
        {
            cout << "Danh sach rong.";
        }
        else
        {
            for (Node *p = head; p != NULL; p = p->next)
            {
                cout << p->data << " ";
            }
            cout << endl;
        }
    }

    int &operator[](int index)
    {
        int i = 0;
        for (Node *p = head; p != NULL; p = p->next)
        {
            if (i == index)
            {
                return p->data;
            }
            i++;
        }
    }

    void erase(int position)
    {
        if (position < 1 || position > length || head == NULL)
        {
            cout << "Vi tri khon hop le." << endl;
            return;
        }
        length--;
        Node *new_node = head;
        if (position == 1)
        {
            head = head->next;
            delete new_node;
        }
        else
        {
            for (int i = 1; i < position - 1; i++)
            {
                new_node = new_node->next;
            }
            Node *temp_node = new_node->next;
            new_node->next = temp_node->next;
            if (temp_node == tail)
                tail = temp_node;
            delete temp_node;
        }
    }
    void push_back(int value)
    {
        Node *new_node = new Node(value);
        length++;
        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
            return;
        }
        tail->next = new_node;
        tail = new_node;
    }
    void insert_at(int value, int position)
    {
        if (position < 1 || position > length + 1)
        {
            cout << "Vi tri khong hop le!" << endl;
            return;
        }
        length++;
        Node *new_node = new Node(value);
        if (position == 1)
        {
            new_node->next = head;
            head = new_node;
            if (length == 0)
                tail = new_node;
        }
        else
        {
            Node *p = head;
            for (int i = 1; i < position - 1; i++)
            {
                p = p->next;
            }
            new_node->next = p->next;
            p->next = new_node;
            if(new_node->next == NULL){
                tail = new_node;
            }
        }
    }
    void updateAt(int position, int newValue)
    {
        if (position < 1 || position > length)
        {
            cout << "Vi tri khong hop le!" << endl;
            return;
        }

        Node *temp = head;
        for (int i = 1; i < position; ++i)
        {
            temp = temp->next;
        }
        temp->data = newValue;
    }
    void reverse()
    {
        if (head == nullptr)
            return;

        Node *prev = nullptr;
        Node *current = head;
        Node *next = nullptr;
        tail = head;

        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
};

int main()
{
    List l;
    l.push_back(10);
    l.push_back(15);
    l.push_back(20);
    l.push_back(25);
    l.push_back(30);
    l.push_back(35);
    // l.erase(3);
    l.insert_at(40, 3);
    // l[1] = 20;
    l.print_all();
    l.reverse();
    l.print_all();
}