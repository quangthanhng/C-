#include <iostream>
using namespace std;

const int MAX = 100; 
bool solve(int startNode, int V, int adjList[][MAX]) {
    bool visited[MAX] = {false};
    int queue[MAX];
    int front = 0, rear = 0;

    queue[rear++] = startNode;
    visited[startNode] = true;

    int count = 0;
    while (front < rear) {
        int current = queue[front++];
        count++;

        for (int i = 0; i < V; i++) {
            if (adjList[current][i] && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
    return count == V;
}

int main() {
    int V, E;
    cin >> V >> E;

    int labels[MAX];
    for (int i = 0; i < V; i++) {
        cin >> labels[i];
    }

    int adjList[MAX][MAX] = {0}; 
    int reverseAdjList[MAX][MAX] = {0}; 

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u][v] = 1;
        reverseAdjList[v][u] = 1;
    }

    for (int i = 0; i < V; i++) {
        if (solve(i, V, reverseAdjList)) {
            cout << labels[i] << endl;
            return 0;
        }
    }

    cout << "Not Found!" << endl;
    return 0;
}
