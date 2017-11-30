#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define M_PI                3.14159265358979323846

const int MAXN = 1e5+5;
ll fact[MAXN], invp[MAXN];

void init(){
    fact[0] = 1, invp[0] = 1;
    for(int i = 1; i < MAXN; i++)
        fact[i] = (fact[i-1] * i) % MOD;
    invp[MAXN-1] = invFermat(fact[MAXN-1], MOD);
    for(int i = MAXN-2; i >= 1; i--)
        invp[i] = (invp[i+1] * (i+1)) % MOD;
}

ll nCr(int n, int r){
    if(r < 0 || r > n)  return 0;
    return (fact[n] * ((invp[n-r] * invp[r]) % MOD)) % MOD;
}

int main(){
    io;
    init();
    cout << nCr(5, 3) << endl;
    return 0;
}