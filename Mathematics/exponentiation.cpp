#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
typedef long long ll;
/*
Calcular de forma eficiente a^b modulo 10^9+7.

Modular Exponentiation: calculation takes only O(log n) time.
*/

int modPow(int a, int b) {
    if(b == 0) return 1;
    ll res = modPow(a, b/2);
    res = res * res % mod;
    if(b % 2 == 1) res = res * a % mod;
    return res;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  while(n>0){
    int a, b;
    cin >> a >> b;
    n--;
    cout <<  modPow(a, b) << "\n";
  }
}
// g++ -std=gnu++17 -O2 -static -o c exponentiation.cpp && ./c