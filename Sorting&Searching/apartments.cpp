// Distribuir apartamentos de acordo com o tamanho desejado pelos clientes.
#include <bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0)->sync_with_stdio(0);
  int n,m;
  // A diferença máxima permitida é long long, pois será usada potência
  long long k;
  cin >> n >> m >> k;
  vector<int>custormers(n);
  vector<int>apartments(m);
  for (int i = 0; i < n; i ++){
    cin >> custormers[i];
  }
  for(int j = 0; j < m; j ++){
    cin >> apartments[j];
  }
  // Ordenamos os vetores cliente e apartamentos
  sort(custormers.begin(),custormers.end());
  sort(apartments.begin(),apartments.end());
  int z=0;
  int count = 0;
  // Para cada cliente, percorremos o vetor de apartamentos
  for(int x = 0; x < n; x++){
    for(int y = z; y < m; y++){
      int difference = apartments[y] - custormers[x];
      // Diferença pode ser negativa -> potência
      long long potencia = pow((difference),2);
      if(potencia <= pow(k,2)) {
        count += 1;
        // Para evitar o mesmo apartamento e contagem desnecessária
        z = y+1;
        break;
      }
      /*A partir do momento em que o apartamento se torna maior que o 
      tamanho desejado pelo cliente e que não passou pela condição acima,
      os próximos apartamentos não atenderão, pois serão ainda maiores, mais
      distantes do valor solicitado*/
      if(apartments[y] > custormers[x]){
        // O primeiro apartamento a ser analisado pelo próximo cliente (de onde parou)
        z = y;
        break;
      }
    }
  }
  cout << count << "\n";
}