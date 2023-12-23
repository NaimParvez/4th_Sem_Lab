#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    int V, E;
    vector<pair<int, pair<int, int>>> edges;

    Graph(int V, int E) {
        this->V = V;
        this->E = E;
    }

    void addEdge(int u, int v, int w) {
        edges.push_back({w, {u, v}});
    }

    // Kruskal's algorithm to find Minimum Spanning Tree
    vector<pair<int, pair<int, int>>> kruskalMST() {
        sort(edges.begin(), edges.end());

        vector<pair<int, pair<int, int>>> result;
        vector<int> parent(V);

        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }

        int edgeCount = 0;
        for (auto edge : edges) {
            int u = edge.second.first;
            int v = edge.second.second;
            int w = edge.first;

            int setU = findSet(parent, u);
            int setV = findSet(parent, v);

            if (setU != setV) {
                result.push_back({w, {u, v}});
                unionSets(parent, setU, setV);
                edgeCount++;
            }

            if (edgeCount == V - 1) {
                break;
            }
        }

        return result;
    }

private:
    int findSet(vector<int> &parent, int i) {
        if (parent[i] == i) {
            return i;
        }
        return findSet(parent, parent[i]);
    }

    void unionSets(vector<int> &parent, int u, int v) {
        int setU = findSet(parent, u);
        int setV = findSet(parent, v);
        parent[setU] = setV;
    }
};

int main() {
    ifstream inputFile("kruskal_input.txt");

    if (!inputFile.is_open()) {
        cerr << "Error: Could not open the input file." << endl;
        return 1;
    }

    int vertices, edges;
    inputFile >> vertices >> edges;

    Graph g(vertices, edges);

    int u, v, w;
    for (int i = 0; i < edges; i++) {
        inputFile >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    inputFile.close();

    cout << "Edges in Minimum Spanning Tree (Kruskal's Algorithm):" << endl;
    vector<pair<int, pair<int, int>>> result = g.kruskalMST();

    for (auto edge : result) {
        cout << edge.second.first << " - " << edge.second.second << " : " << edge.first << endl;
    }

    return 0;
}
