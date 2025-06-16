#include <bits/stdc++.h>
using namespace std;
/*
Reordenar as letras de uma string de modo que se torne um palíndromo.
*/

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string n;
  cin >> n;
  map<string, int>letras;

  for(int i=0; i<n.size(); i++) {
    string c (1, n[i]);
    if(letras.find(c) == letras.end()){
      letras[c] = 1;
    } else {
      letras[c] ++;
    }
  }
  string p;
  string q = "";
  string sequencia;
  int ind = 1;
  bool flag = true;
  for(auto par : letras) {
    for(int i = 0; i < par.second; i++) {
        sequencia += par.first;
    }
    if(par.second % 2 != 0) {
      ind--;
      q = sequencia;
      if(ind == -1) {
        flag = false;
        break;
      }
    } else {
      p.insert(p.size()/2, sequencia);
    }    
    sequencia = "";
  }
  p.insert(p.size()/2, q);
  if(flag) {
    cout << p << "\n";
  } else {
    cout << "NO SOLUTION\n";
  }
}

// g++ -std=gnu++17 -O2 -static -o c palindromeReorder.cpp && ./c