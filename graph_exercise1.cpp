#include <iostream>
#include <string>
using namespace std;

struct Graph {
    int V, E;              // Số đỉnh và số cạnh
    string* labels;        // Nhãn của các đỉnh
    int* degrees;          // Mảng lưu bậc của từng đỉnh

    // Khởi tạo đồ thị
    Graph(int vertices, int edges) {
        V = vertices;
        E = edges;
        labels = new string[V];
        degrees = new int[V](); // Khởi tạo tất cả giá trị là 0
    }

    // Hủy đồ thị
    ~Graph() {
        delete[] labels;
        delete[] degrees;
    }

    // Tìm chỉ số của một nhãn
    int getIndex(const string& label) {
        for (int i = 0; i < V; i++) {
            if (labels[i] == label) return i;
        }
        return -1; // Không tìm thấy
    }

    // Đọc cạnh và cập nhật bậc
    void addEdge(const string& u, const string& v) {
        int uIndex = getIndex(u);
        int vIndex = getIndex(v);

        if (uIndex != -1 && vIndex != -1) {
            degrees[uIndex]++;
            degrees[vIndex]++;
        }
    }

    // In bậc của các đỉnh
    void printDegrees() {
        for (int i = 0; i < V; i++) {
            cout << labels[i] << ": " << degrees[i] << endl;
        }
    }
};

int main() {
    int V, E;
    cin >> V >> E;

    // Tạo đồ thị
    Graph graph(V, E);

    // Nhập nhãn các đỉnh
    for (int i = 0; i < V; i++) {
        cin >> graph.labels[i];
    }

    // Đọc các cạnh
    for (int i = 0; i < E; i++) {
        string u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    // In bậc của từng đỉnh
    graph.printDegrees();

    return 0;
}
