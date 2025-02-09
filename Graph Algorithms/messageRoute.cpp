#include <bits/stdc++.h>
using namespace std;
/*
Rota da Mensagem
Descobrir se é possível o pc 1 enviar mensagem para o pc n.
Se for possível, descrever a menor rota.
*/

/*
Breadth First Search
Aplicando-se BFS, descobrimos qual o menor caminho entre 1 e n
Para descrever o percurso, fazemos o caminho inverso
Há um vínculo entre o vértice e o vizinho
*/
void bfs(int node, vector<bool>&visitado, vector<vector<int>>&adj, vector<pair<int,int>>distAndVizin){
    int num_vertices = adj.size()-1;
    queue<int>fila;
    fila.push(node);
    visitado[node] = true;
    distAndVizin[node].first = 0;
    while(!fila.empty()) {
        int vertice = fila.front(); fila.pop();
        //cout<<vertice<<" ";
        for(auto vizinho : adj[vertice]){
            if(!visitado[vizinho]){
                visitado[vizinho] = true;
                distAndVizin[vizinho].first = distAndVizin[vertice].first+1;
                distAndVizin[vizinho].second = vertice;
                fila.push(vizinho);
            }
        }
    }
   vector<int>neighbors;
   int q = num_vertices;
   while(q >= 1){
    neighbors.push_back(q);
    q = distAndVizin[q].second;
   }
   bool notfirst = true;
   for(int i=neighbors.size()-1; i>=0; i--){
    if(neighbors[i] != 1 and notfirst) {
        cout << "IMPOSSIBLE";
    } else {
        if(notfirst) {
          cout << distAndVizin[num_vertices].first + 1 <<"\n";
        }
        notfirst = false;
        cout << neighbors[i] << " ";
    }
   }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<bool>visitado(n+1, false);
    vector<vector<int>>adj(n+1);
    vector<pair<int, int>>distAndVizin(n+1);
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    bfs(1, visitado, adj, distAndVizin);
    cout<<"\n";
}

//g++ -std=gnu++17 -O2 -static -o c messageRoute.cpp