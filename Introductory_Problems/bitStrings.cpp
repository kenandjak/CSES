#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
/*
Calcular o número de sequências de bits de tamanho n.
Em outras palavras, basicamente calcular 2^n


A ideia inicial é aplicar a função de potência, 
mas o pow(2, n) gera perda de precisão.
Aqui foi aplicada a lógica da programação dinâmica
*/

int dP(int valor, vector<int>&memo) {
    memo[0] = 1; // 2⁰ == 1
    for(int i=1; i <= valor; i++) {
      memo[i] = 2 * memo[i-1];
      memo[i] %= mod;
    }
    return memo[valor];
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int>memo(n+1, 0);
  cout <<  dP(n, memo) << "\n";
}
// g++ -std=gnu++17 -O2 -static -o c bitStrings.cpp && ./c
