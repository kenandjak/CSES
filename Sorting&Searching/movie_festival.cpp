// A quantidade máxima de filmes inteiros que se pode assistir.
#include <bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  int starting, ending;
  vector<pair<int,int>>movies;
  for(int i = 0; i<n; i++){
    cin >> starting >> ending;
    // A ideia é ordenar pelo fim - escolher o filme que termina primeiro
    movies.push_back({ending,starting});
  }
  // Ordenamos de acordo com o ending
  sort(movies.begin(),movies.end());
  int k=0;
  // Para contar o 1º filme:
  int count = 1;
  // Não é até 2*n - dá runtime error; o par {e,s} conta como 1
  // n-1, pois do atual avaliamos o próximo
  for (int i=0; i<n-1; i++){
    // O início do próximo filme deve ser maior ou igual ao fim do filme atual
    // Filme em sequência - ex.: {start,end}: {2,5},{6,8},{8,15}
    if(movies[i+1].second >= movies[k].first){
      count +=1;
      k = i + 1;
    } 
  }
  cout << count << "\n";
}
