#include <iostream>
#include <vector>
#include <queue>
#include <climits>

struct edge {
    int s; // starting node
    int t; // ending node
};

struct weightedEdge {
    int s;     // starting node
    int t;     // ending node
    double w;  // weight of the edge
};

class Graph {
private:
    int** adjMatrix;
    int n;          // number of nodes
    bool directed;  // true if the graph is directed

public:
    Graph(int n, int m, bool directed);
    Graph(int n, int m, edge edges[], bool directed);
    ~Graph();

    void BFS(int s);
    void print();
};

Graph::Graph(int n, int m, bool directed) : n(n), directed(directed) {
    adjMatrix = new int*[n];
    for (int i = 0; i < n; i++) {
        adjMatrix[i] = new int[n]{0};
    }

    for (int i = 0; i < m; i++) {
        int u = rand() % n;
        int v = rand() % n;
        adjMatrix[u][v] = 1;
        if (!directed) adjMatrix[v][u] = 1;
    }
}

Graph::Graph(int n, int m, edge edges[], bool directed) : n(n), directed(directed) {
    adjMatrix = new int*[n];
    for (int i = 0; i < n; i++) {
        adjMatrix[i] = new int[n]{0};
    }

    for (int i = 0; i < m; i++) {
        adjMatrix[edges[i].s][edges[i].t] = 1;
        if (!directed) adjMatrix[edges[i].t][edges[i].s] = 1;
    }
}

Graph::~Graph() {
    for (int i = 0; i < n; i++) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
}

void Graph::BFS(int s) {
    std::vector<bool> visited(n, false);
    std::queue<int> q;

    visited[s] = true;
    q.push(s);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        std::cout << node << " ";

        for (int i = 0; i < n; i++) {
            if (adjMatrix[node][i] && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    std::cout << std::endl;
}

void Graph::print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << adjMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

class WeightedGraphDijkstra {
private:
    double** adjWeightMatrix;
    int n;          // number of nodes
    bool directed;  // true if the graph is directed

public:
    WeightedGraphDijkstra(int n, int m, bool directed);
    WeightedGraphDijkstra(int n, int m, weightedEdge edges[], bool directed);
    ~WeightedGraphDijkstra();

    void Dijkstra(int s);
    void print();
};

WeightedGraphDijkstra::WeightedGraphDijkstra(int n, int m, bool directed) : n(n), directed(directed) {
    adjWeightMatrix = new double*[n];
    for (int i = 0; i < n; i++) {
        adjWeightMatrix[i] = new double[n];
        for (int j = 0; j < n; j++) {
            adjWeightMatrix[i][j] = (i == j) ? 0 : INT_MAX;
        }
    }

    for (int i = 0; i < m; i++) {
        int u = rand() % n;
        int v = rand() % n;
        double w = (rand() % 100) / 10.0;
        adjWeightMatrix[u][v] = w;
        if (!directed) adjWeightMatrix[v][u] = w;
    }
}

WeightedGraphDijkstra::WeightedGraphDijkstra(int n, int m, weightedEdge edges[], bool directed) : n(n), directed(directed) {
    adjWeightMatrix = new double*[n];
    for (int i = 0; i < n; i++) {
        adjWeightMatrix[i] = new double[n];
        for (int j = 0; j < n; j++) {
            adjWeightMatrix[i][j] = (i == j) ? 0 : INT_MAX;
        }
    }

    for (int i = 0; i < m; i++) {
        adjWeightMatrix[edges[i].s][edges[i].t] = edges[i].w;
        if (!directed) adjWeightMatrix[edges[i].t][edges[i].s] = edges[i].w;
    }
}

WeightedGraphDijkstra::~WeightedGraphDijkstra() {
    for (int i = 0; i < n; i++) {
        delete[] adjWeightMatrix[i];
    }
    delete[] adjWeightMatrix;
}

void WeightedGraphDijkstra::Dijkstra(int s) {
    std::vector<double> dist(n, INT_MAX);
    std::vector<int> parent(n, -1);
    std::vector<bool> visited(n, false);

    dist[s] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u])) u = i;
        }

        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && adjWeightMatrix[u][v] != INT_MAX && dist[u] + adjWeightMatrix[u][v] < dist[v]) {
                dist[v] = dist[u] + adjWeightMatrix[u][v];
                parent[v] = u;
            }
        }
    }

    std::cout << "Node\tDistance\tParent" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << i << "\t" << dist[i] << "\t" << parent[i] << std::endl;
    }
}

void WeightedGraphDijkstra::print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adjWeightMatrix[i][j] == INT_MAX)
                std::cout << "INF ";
            else
                std::cout << adjWeightMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    edge undirectedGraph[] = {{0, 1}, {0, 4}, {0, 6}, {1, 2}, {1, 7}, {2, 3}, {2, 8}, {3, 5}, {3, 9}, {4, 7}, {5, 8}, {6, 7}, {7, 8}, {8, 9}};
    Graph g(10, 14, undirectedGraph, false);
    g.print();
    std::cout << "BFS starting from node 0:" << std::endl;
    g.BFS(0);

    weightedEdge weightedGraph[] = {{0, 1, 4}, {0, 2, 2}, {1, 2, 1}, {1, 3, 5}, {2, 3, 8}, {2, 4, 10}, {3, 4, 2}};
    WeightedGraphDijkstra wg(5, 7, weightedGraph, true);
    wg.print();
    std::cout << "\nDijkstra starting from node 0:" << std::endl;
    wg.Dijkstra(0);

    return 0;
}
