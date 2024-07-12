// Dado um array de inteiros, modificá-lo para torná-lo crescente.
#include <bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int>x(n);
  for(int i = 0; i < n; i++){
    cin >> x[i];
  }
  // Devido às "autossomas", o tipo de count deve ser long long
  // Pois o valor máximo de cada número é o limite para o tipo int (10⁹)
  long long count = 0;
  for(int i = 0; i < n - 1; i ++){
    if(x[i] > x[i+1]){
        count += x[i] - x[i+1];
        x[i+1] = x[i];
    }
  }
  cout << count << "\n";
}
