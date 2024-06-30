// Calcular o número de valores distintos da lista.
#include <bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int>v(n);
  for(int i = 0; i < n; i++){
    cin >> v[i];
  }
  // Ordenação dos valores - facilita a verificação 
  sort(v.begin(),v.end());
  // Inicia com 1 para contar o 1º valor da lista, pois o nº de valores n >= 1
  int count = 1;
  for(int i = 0; i < n-1; i++){
    // Como a comparação é com o próximo número, i vai até n-1, não até n
    if(v[i] != v[i+1]){
      count += 1;
    }
  }
  cout << count << "\n";
}