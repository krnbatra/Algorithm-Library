/*Let's get high :D*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define M_PI                3.14159265358979323846

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}

const int MAXN = 1e5+5;
string str;
int n;
ll MOD1 = MOD;
ll p1 = 43LL;
ll power1[MAXN];
ll prefix[MAXN], suffix[MAXN];

void init(){
    power1[0] = 1;
    for(int i = 1;i <= 100000; i++)
        power1[i] = (power1[i-1] * p1) % MOD;
}

void calPrefix(){
    prefix[0] = str[0] % MOD;
    for(int i = 1; i < str.size(); i++)
        prefix[i] = (prefix[i-1] + (str[i] * power1[i]) % MOD) % MOD;
}

void calSuffix(){
    suffix[0] = str[n-1] % MOD;
    int j = 1;
    
    for(int i = n-2;i >= 0; i--){
        suffix[j] = (suffix[j-1] + (str[i] * power1[j]) % MOD) % MOD;
        j++;
    }
}

int main(){
    io;
    init();
    str = "bab";
    n = str.size();
    
    int l, r;
    cin >> l >> r;
    
    calPrefix();
    calSuffix();

    ll hash;
    if(l > 0)
        hash = ((prefix[r] - prefix[l-1]) * invFermat(power1[l], MOD)) % MOD;
    else
        hash = prefix[r];
    
    ll revHash;
    if(r > 0)
        revHash = ((suffix[n-l-1] - suffix[n-r-2]) * invFermat(power1[n-r-1], MOD)) % MOD;
    else
        revHash = suffix[0];
    
    cout << hash << ' ' << revHash << endl;
    return 0;
}