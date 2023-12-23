#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    int V;
    list<int> *adj;

    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int getMaxDegreeVertex() {
        int maxDegree = -1, maxDegreeVertex = -1;

        for (int i = 0; i < V; ++i) {
            int degree = adj[i].size();
            if (degree > maxDegree) {
                maxDegree = degree;
                maxDegreeVertex = i;
            }
        }

        return maxDegreeVertex;
    }

    void splitGreedy() {
        int splitVertex = getMaxDegreeVertex();
        cout << "Splitting the tree at vertex " << splitVertex << endl;
    }
};

int main() {
    ifstream inputFile("tree_input.txt");

    if (!inputFile.is_open()) {
        cerr << "Error: Could not open the input file." << endl;
        return 1;
    }

    int V, u, v;
    inputFile >> V;

    Graph g(V);

    while (inputFile >> u >> v) {
        g.addEdge(u, v);
    }

    inputFile.close();

    cout << "Tree vertex splitting using greedy method:" << endl;
    g.splitGreedy();

    return 0;
}
