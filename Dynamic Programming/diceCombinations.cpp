#include <bits/stdc++.h>
using namespace std;
int m = 1e9 + 7;
/*
Combinações de dados:
Contar o número de maneiras de construir a soma n.
*/
int dynamicProgramming(int valor, vector<int>&dice) {
    vector<int>count(valor+1, 0);
    count[0] = 1;
    for(int i=1; i <= valor; i++) {
        for(auto d : dice) {
            if(i - d >= 0) {
                count[i] += count[i-d];
                count[i] %= m;
            }
        }
    }
    return count[valor];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int>dice = {1, 2, 3, 4, 5, 6};
    cout << dynamicProgramming(n, dice) << "\n";

}

//g++ -std=gnu++17 -O2 -static -o c diceCombinations.cpp