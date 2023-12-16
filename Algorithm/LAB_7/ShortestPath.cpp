#include<bits/stdc++.h>
using namespace std;
const int infinite = 1e7;

void SingleSourceShortestPath(vector<vector<pair<int,int>>> graph, vector<int>& dist, int n) {
    int source = 1;
    dist[source] = 0;
    set<pair<int, int>> s;
    s.insert({0, source});
    cout << "Each value of distance after checking : " << endl;
    while (!s.empty()) {
        for (int i = 1; i <= n; i++) {
            cout << dist[i] << " ";
        }
        cout << endl;
        auto x = *(s.begin());
        s.erase(x);
        for (auto it : graph[x.second]) {
            if (dist[it.first] > dist[x.second] + it.second) {
                s.erase({dist[it.first], it.first});
                dist[it.first] = dist[x.second] + it.second;
                s.insert({dist[it.first], it.first});
            }
        }
    }
    cout << endl << "The Final Distance from Source to all : ";
    for (int i = 1; i <= n; i++) {
        if (dist[i] < infinite)
        {
            char sourceVertex = 'S';
            char targetVertex = 'A' + i - 2;
            cout << sourceVertex << " --> " << targetVertex << ": " << dist[i] << endl;
        }
    }
    cout << endl;
}

int charToIndex(char vertex) {
    if (vertex == 'S') return 1;
    return vertex - 'A' + 2;
}

int main() {
    // ofstream outputFile("graph");
    // int n, m;
    // cout << "Enter the number of vertices and edges: ";
    // cin >> n >> m;

    // outputFile << n << " " << m << endl;

    // cout << "Enter the edges (u, v, w):" << endl;
    // for (int i = 0; i < m; i++) {
    //     char u, v;
    //     int w;
    //     cin >> u >> v >> w;
    //     outputFile << charToIndex(u) << " " << charToIndex(v) << " " << w << endl;
    // }
    // outputFile.close();

    ifstream inputFile("graph");
    int n,m;
    inputFile >> n >> m;
    vector<int> dist(n + 1, infinite);
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        inputFile >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    inputFile.close();

    SingleSourceShortestPath(graph, dist, n);
}
