#include <iostream>
using namespace std;

#define MAX 10    
#define MAX_DEG 10 

class Graph {
public:
    int V;
    int adjList[MAX][MAX_DEG];
    int adjCount[MAX];
    int adjMatrix[MAX][MAX];

    Graph(int vertices) {
        V = vertices;
        for (int i = 1; i <= V; i++) {
            adjCount[i] = 0;
            for (int j = 1; j <= V; j++)
                adjMatrix[i][j] = 0;
        }
    }

    void addEdge(int u, int v) {
        adjList[u][adjCount[u]++] = v;
        adjList[v][adjCount[v]++] = u;

        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    void displayAdjList() {
        cout << "Adjacency List:\n";
        for (int i = 1; i <= V; i++) {
            cout << i << " -> ";
            for (int j = 0; j < adjCount[i]; j++)
                cout << adjList[i][j] << " ";
            cout << endl;
        }
    }

    void displayAdjMatrix() {
        cout << "\nAdjacency Matrix:\n";
        for (int i = 1; i <= V; i++) {
            for (int j = 1; j <= V; j++)
                cout << adjMatrix[i][j] << " ";
            cout << endl;
        }
    }

    void BFS(int start) {
        int visited[MAX] = {0};
        int queueArr[MAX], front = 0, rear = 0;

        cout << "\nBFS Traversal: ";
        queueArr[rear++] = start;
        visited[start] = 1;

        while (front < rear) {
            int node = queueArr[front++];
            cout << node << " ";

            for (int i = 0; i < adjCount[node]; i++) {
                int v = adjList[node][i];
                if (!visited[v]) {
                    visited[v] = 1;
                    queueArr[rear++] = v;
                }
            }
        }
    }


    void DFSUtil(int node, int visited[]) {
        visited[node] = 1;
        cout << node << " ";

        for (int i = 0; i < adjCount[node]; i++) {
            int v = adjList[node][i];
            if (!visited[v])
                DFSUtil(v, visited);
        }
    }

    void DFS(int start) {
        int visited[MAX] = {0};
        cout << "\nDFS Traversal: ";
        DFSUtil(start, visited);
        cout << endl;
    }
};

int main() {
    Graph g(5);

    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    g.displayAdjList();
    g.displayAdjMatrix();

    g.BFS(1);
    g.DFS(1);

    return 0;
}
