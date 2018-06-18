#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define M_PI                3.14159265358979323846

template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}

const int N = 1e5 + 5;

ll fact[N], invp[N];

void init(){
    fact[0] = 1, invp[0] = 1;
    for(int i = 1; i < N; i++)
        fact[i] = (fact[i-1] * i) % MOD;
    invp[N - 1] = invFermat(fact[N-1], MOD);
    for(int i = N - 2; i >= 1; i--)
        invp[i] = ( invp[i + 1] * (i + 1)) % MOD;
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