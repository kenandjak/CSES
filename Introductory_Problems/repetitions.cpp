// Dada uma sequência de DNA, encontrar a maior substring de caracteres semelhantes adjacentes.
#include <bits/stdc++.h>
using namespace std;

int main(){
  string dna;
  cin >> dna;
  // A string conterá pelo menos 1 caracter
  int x = 1, y = 0;
  
  for(int i = 0; i < dna.size() - 1; i++){
    // Se o caracter atual for igual ao próximo, contaremos essa subsequência sequência:
      if(dna[i] == dna[i+1]) x += 1;
      // Se não for, analisamos qual a maior subsequência que temos.
      // Se a contagem atual(x) for maio que a anterior(y), y recebe x:
      else{
        if (y < x) y = x;
        x = 1;
      }
  }
  // A contagem pode ter terminado com x sem ser "resetado" (x=1)
  // Então, analisamos e imprimimos o maior valor:
  cout << max(x,y) << "\n";
}
