#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph {
private:
    int V; // Số đỉnh
    vector<list<int>> adj; // Danh sách kề

public:
    // Constructor
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    // Thêm cạnh vào đồ thị
    void addEdge(int v, int w) {
        adj[v].push_back(w); // Thêm w vào danh sách kề của v
    }

    // In đồ thị
    void printGraph() {
        for (int i = 0; i < V; ++i) {
            cout << "Đỉnh " << i << ": ";
            for (auto v : adj[i]) {
                cout << v << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(5); // Khởi tạo đồ thị có 5 đỉnh

    g.addEdge(0, 1); // Thêm cạnh từ 0 đến 1
    g.addEdge(0, 4); // Thêm cạnh từ 0 đến 4
    g.addEdge(1, 2); // Thêm cạnh từ 1 đến 2
    g.addEdge(1, 3); // Thêm cạnh từ 1 đến 3
    g.addEdge(1, 4); // Thêm cạnh từ 1 đến 4
    g.addEdge(2, 3); // Thêm cạnh từ 2 đến 3
    g.addEdge(3, 4); // Thêm cạnh từ 3 đến 4

    g.printGraph(); // In ra đồ thị

    return 0;
}
