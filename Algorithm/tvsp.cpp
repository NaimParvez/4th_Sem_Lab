#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

map<ll,vector<ll> >graph;
ll tolerance;
set<ll>boosterPlacement;
ll weight[500][500]={-1};
ll dfs(ll node, ll par){
    if(graph.find(node)==graph.end()){
        return 0;
    }
    ll d = 0;
    for(auto it:graph[node]){
        d = max(weight[node][it]+dfs(it, node),d);
    }
    if(par!=-1 && (d + weight[par][node]>tolerance)) {
        boosterPlacement.insert(node);
        d=0;
    }
    return d;
}
int main()
{
    ll u,v,w;
    ifstream in("datatv.txt");
    ofstream out;
    while(in>>u>>v>>w){
        graph[u].pb(v);
        weight[u][v] = w;
    }
    out.close();

    ifstream kki;
    ofstream outt("resulttv.txt");

    cout<<"Enter Tolerance: ";
    cin>>tolerance;
    dfs(1,-1);
    cout<<"Booster Placements: ";
    for(auto it: boosterPlacement){
        cout<<it<<" ";
        outt<<it<<" ";
    }
}
