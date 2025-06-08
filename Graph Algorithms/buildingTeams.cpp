#include <bits/stdc++.h>
using namespace std;
/*
Construindo times:
Em uma classe, dividir os alunos de modo que dois alunos do mesmo time não sejam amigos.
*/

// Bipartite Graph
bool dfs(int node, vector<bool>&visitado, vector<vector<int>>&adj, int color, vector<int>&colors) {
    visitado[node] = true;
    colors[node] = color;
   
    for(auto vizinho : adj[node]) {
        if(!visitado[vizinho]) {
            // Bitwise XOR operator:
            // 0 ^ 1 == 1 and 1 ^ 1 == 0
            bool sem_conflito = dfs(vizinho, visitado, adj, color^1, colors);
            if(sem_conflito == false) return false;
        } else {
            if(colors[node] == colors[vizinho]) return false;
        }
    }
    return true;
}

int main(){
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<bool>visitado(n+1, false);
  vector<int>colors(n+1, 0);
  vector<vector<int>>adj(n+1);
  for(int i=0; i<m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  bool indicador = true;
  for(int j=1; j<= n; j++) {
    if(!visitado[j]) {
        indicador = dfs(j, visitado, adj, 0, colors);
        if(indicador == false) break;
    }
  }
  if(!indicador){
    cout << "IMPOSSIBLE";
  } else {
    for(int i=1; i<=n; i++) {
        cout << colors[i]+1 << " ";
    }
  }
  cout << "\n";
}

//g++ -std=gnu++17 -O2 -static -o c buildingTeams.cpp && ./c
