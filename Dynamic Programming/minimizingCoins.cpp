#include <bits/stdc++.h>
using namespace std;
/*
Usar o número mínimo de moedas para obter a soma dada.
*/

void dynamicProgramming(int valor, vector<int>&moedas) {
    vector<int>dp(valor+1, INT_MAX);
    dp[0] = 0;
    for(int i=1; i <= valor; i++) {
        for(auto moeda : moedas) {
            if(i - moeda >= 0 and dp[i-moeda] != INT_MAX) {
                dp[i] = min(dp[i], dp[i-moeda]+1);
            }
        }
    }
    if(dp[valor] == INT_MAX){
        cout << -1 << "\n";
    }
    else {
        cout << dp[valor] << "\n";
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, x;
    cin >> n >> x;
    vector<int>coins(n);
    for(int c=0; c<n; c++){
        cin >> coins[c];
    }
    dynamicProgramming(x, coins);
}
//g++ -std=gnu++17 -O2 -static -o c minimizingCoins.cpp