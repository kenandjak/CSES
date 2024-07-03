// Quantidade máxima de clientes presentes no restaurante
#include <bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  int arrival, leaving;
  vector<pair<int,int>>v;
  for(int i = 0; i < n; i++){
    cin >> arrival >> leaving;
    // Quando um cliente chega, adiciona 1
    v.push_back({arrival,1});
    // Quando um cliente sai, subtrai 1
    v.push_back({leaving,-1});
    // Estão sendo adicionados 2n elementos (dois pares)
  }
  // Ordena os valores em um tempo crescente, de acordo com o 1º elem do par
  sort(v.begin(),v.end());
  int count = 0;
  int maior = 0;
  // É preciso fazer a verificação até 2n, não só até n
  for(int j = 0; j < 2*n; j++){
    count += v[j].second;
    if (count > maior){
      maior = count;
    }
  }
  cout << maior << "\n";
}
