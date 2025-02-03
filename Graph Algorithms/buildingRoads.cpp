#include <bits/stdc++.h>
using namespace std;
/*
Construindo estradas:
Descobrir o número mínimo de estradas de modo que haja uma rota entre duas cidades.
Determinar quais são as estradas.
*/

/*
A quantidade de estradas necessárias k é igual à quantidade de componentes menos 1.
*/
void dfs(int node, vector<bool>&visitado, vector<vector<int>>&adj) {
    visitado[node] = true;

    for(auto vizinho : adj[node]) {
        if(!visitado[vizinho]) {
            dfs(vizinho, visitado, adj);
        }
    }
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<bool>visitado(n+1, false);
    vector<vector<int>>adj(n+1);
    for(int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }    
    int k = -1;
    vector<int>roads;
    for(int j=1; j<= n; j++) {
        if(!visitado[j]) {
            k += 1;
            roads.push_back(j);
            dfs(j, visitado, adj);
        }
    }
    cout << k << "\n";
    for(int j=0; j<roads.size()-1; j++) {
        cout << roads[j] << " " << roads[j+1] << "\n";
    }
}

//g++ -std=gnu++17 -O2 -static -o c buildingRoads.cpp