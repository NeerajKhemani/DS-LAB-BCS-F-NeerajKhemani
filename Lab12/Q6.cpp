#include <iostream>
using namespace std;

#define INF 99999
#define N 7

class DijkstraGraph {
public:
    int V;
    int w[N][N];

    DijkstraGraph(int vertices) {
        V = vertices;
        for (int i = 1; i <= V; i++)
            for (int j = 1; j <= V; j++)
                w[i][j] = (i == j ? 0 : INF);
    }

    void addEdge(int u, int v, int weight) {
        w[u][v] = weight;
        w[v][u] = weight;
    }

    void dijkstra(int start, int end) {
        int dist[N], visited[N], parent[N];

        for (int i = 1; i <= V; i++) {
            dist[i] = INF;
            visited[i] = 0;
            parent[i] = -1;
        }

        dist[start] = 0;

        for (int k = 1; k <= V; k++) {

            int u = -1, minDist = INF;

            for (int i = 1; i <= V; i++)
                if (!visited[i] && dist[i] < minDist) {
                    minDist = dist[i];
                    u = i;
                }

            visited[u] = 1;

            for (int v = 1; v <= V; v++) {
                if (w[u][v] < INF && dist[u] + w[u][v] < dist[v]) {
                    dist[v] = dist[u] + w[u][v];
                    parent[v] = u;
                }
            }
        }

        cout << "\nShortest Distance (B to E): " << dist[end] << endl;

        cout << "Path: ";
        int path[N], idx = 0;
        for (int v = end; v != -1; v = parent[v])
            path[idx++] = v;
        for (int i = idx - 1; i >= 0; i--)
            cout << path[i] << " ";
    }
};

int main() {
    DijkstraGraph g(6);

    g.addEdge(2, 1, 4);
    g.addEdge(2, 3, 9);
    g.addEdge(1, 4, 8);
    g.addEdge(3, 4, 6);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 6, 4);
    g.addEdge(6, 5, 3);

    g.dijkstra(2, 5); 

    return 0;
}
