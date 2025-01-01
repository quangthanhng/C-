#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

void addNode(Node*& head, int value) {
    if (!head) head = new Node(value);
    else {
        Node* current = head;
        while (current->next) current = current->next;
        current->next = new Node(value);
    }
}

void printList(Node* head) {
    if (!head) cout << "Empty list" << endl;
    else {
        while (head) {
            cout << head->data << " ";
            head = head->next;
        }
        cout << endl;
    }
}

int absDiff(int a, int b) {
    return a > b ? a - b : b - a;
}

vector<pair<int, int>> findMaxDiff(Node* head, int& maxDiff) {
    vector<int> values;
    for (Node* current = head; current; current = current->next) values.push_back(current->data);

    maxDiff = -1;
    vector<pair<int, int>> pairs;
    for (int i = 0; i < values.size(); ++i) {
        for (int j = i + 1; j < values.size(); ++j) {
            int diff = absDiff(values[i], values[j]);
            if (diff > maxDiff) {
                maxDiff = diff;
                pairs = {{i, j}};
            } else if (diff == maxDiff) pairs.push_back({i, j});
        }
    }
    return pairs;
}

void deleteNodes(Node*& head, const vector<int>& indices) {
    vector<bool> toDelete(1000, false);
    for (int idx : indices) toDelete[idx] = true;

    Node *current = head, *prev = nullptr;
    for (int i = 0; current; ++i) {
        if (toDelete[i]) {
            Node* temp = current;
            current = current->next;
            if (!prev) head = current;
            else prev->next = current;
            delete temp;
        } else {
            prev = current;
            current = current->next;
        }
    }
}

int main() {
    Node* head = nullptr;
    int value;
    while (cin >> value && value != 0) addNode(head, value);

    printList(head);

    int maxDiff;
    vector<pair<int, int>> pairs = findMaxDiff(head, maxDiff);

    if (pairs.empty()) cout << "Not Found" << endl;
    else {
        for (auto& p : pairs) cout << p.first << " " << p.second << endl;

        vector<int> indices;
        for (auto& p : pairs) {
            indices.push_back(p.first);
            indices.push_back(p.second);
        }

        deleteNodes(head, indices);

        printList(head);
    }

    return 0;
}