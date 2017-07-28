/*My First Template :D*/
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

ll MOD1 = MOD;
ll MOD2 = MOD+2;
ll p1 = 43LL;
ll p2 = 107LL;
ll power1[MAXN], power2[MAXN];
ll prefix[MAXN], suffix[MAXN];

void init(){
	power1[0] = p1;
	power2[0] = p2;
	for(int i = 1;i <= (int)3e5+5; i++){
		power1[i] = (power1[i-1]*p1) % MOD;
		power2[i] = (power2[i-1]*p2) % MOD2; 
	}
}

void calPrefix(){
	prefix[0] = str[0];
	for(int i = 1; i < str.size(); i++)
		prefix[i] = (prefix[i-1] + (str[i]*mod_exp(26LL, (ll)i, MOD)) % MOD) % MOD;
}

void calSuffix(){
	suffix[0] = str[n-1];
	int j = 1;
	
	for(int i = n-2;i >= 0; i--){
		suffix[j] = (suffix[j-1] + (str[i]*mod_exp(26LL, (ll)j, MOD)) % MOD) % MOD;
		j++;
	}
}

int main(){
    io;
    init();
	string str = "bab";
	int n = str.size();
	
	int l, r;
	cin >> l >> r;
	
	calPrefix();
	calSuffix();

	ll hash;
	if(l > 0)
		hash = ((prefix[r]-prefix[l-1])*invFermat(mod_exp(26LL, (ll)l, MOD), MOD)) % MOD;
	else
		hash = prefix[r];
	
	ll revHash;
	if(r > 0)
		revHash = ((suffix[n-l-1]-suffix[n-r-2])*invFermat(mod_exp(26LL, (ll)n-r-1, MOD), MOD)) % MOD;
	else
		revHash = suffix[0];
	
	cout << hash << ' ' << revHash << endl;
    return 0;
}