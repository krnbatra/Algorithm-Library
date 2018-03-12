#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define M_PI                3.14159265358979323846

template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}

const int MAXN = 1e5 + 5;

string str;
int n;
ll MOD1 = MOD;
ll p1 = 43LL;	// 31 and 53 are also good choices
ll MOD2 = MOD + 2;
ll p2 = 107LL;
ll power1[MAXN], modinv[MAXN];
ll prefix[MAXN], suffix[MAXN];

ll mod_sub(ll a, ll b, ll mod){
    return (a - b + mod) % mod;
}

ll mod_add(ll a, ll b, ll mod){
    return (a + b) % mod;
}

ll mod_mul(ll a, ll b, ll mod){
    return (a * b) % mod;
}

void init(){
    power1[0] = 1;
    modinv[0] = 1;
    ll MODINV = invFermat(p1, MOD);
    for(int i = 1; i < MAXN; i++){
        power1[i] = mod_mul(power1[i - 1], p1, MOD);
        modinv[i] = mod_mul(modinv[i - 1], MODINV, MOD);
    }
}

void prefix_hash(){
    prefix[0] = str[0] - 'a' + 1;
    for(int i = 1; i < str.size(); i++)
        prefix[i] = mod_add(prefix[i - 1], mod_mul(str[i] - 'a' + 1, power1[i], MOD), MOD);
}

void suffix_hash(){
    suffix[0] = str[n-1] - 'a' + 1;
    int j = 1;
    for(int i = n-2; i >= 0; i--){
        suffix[j] = mod_add(suffix[j - 1], mod_mul(str[i] - 'a' + 1, power1[j], MOD), MOD);
        j++;
    }
}

ll cal_hash(int l, int r){
    ll hash;
    if(l > 0)
        hash = mod_mul(mod_sub(prefix[r], prefix[l - 1], MOD), modinv[l], MOD);
    else
        hash = prefix[r];
    return hash;
}

ll cal_revhash(int l, int r){
    ll revHash;
    if(r > 0){
        revHash = mod_mul(mod_sub(suffix[n - l - 1], suffix[n - r - 2], MOD), modinv[n - r - 1], MOD);
    }
    else{
        // r == 0 && l == 0
        revHash = prefix[0];
    }
    return revHash;
}

int main(){
    io;
    init();
    str = "abababababababababa";
    n = str.size();
    
    int l, r;
    cin >> l >> r;
    // check substring [l..r] is palindrome or not
    prefix_hash();
    suffix_hash();

    ll hash = cal_hash(l, r);
    ll revHash = cal_revhash(l, r);
    
    cout << hash << ' ' << revHash << endl;
    return 0;
}