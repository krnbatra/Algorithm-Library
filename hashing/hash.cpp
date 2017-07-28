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

const int MAXN = 6e5+10;

ll MOD1 = MOD;
ll MOD2 = MOD+2;
ll p1 = 43LL;
ll p2 = 107LL;
ll power1[MAXN], power2[MAXN];

void init(){
	power1[0] = p1;
	power2[0] = p2;
	for(int i = 1;i <= (int)3e5+5; i++){
		power1[i] = (power1[i-1]*p1) % MOD;
		power2[i] = (power2[i-1]*p2) % MOD2; 
	}
}

ll get_hash(string &s){
	ll hash = 0;
	for(int i = 0;i < s.size(); i++){
		hash = (hash + s[i]*power1[i]) % MOD;
	}
	return hash;
}

ll get_hash2(string &s){
	ll hash = 0;
	for(int i = 0;i < s.size(); i++){
		hash = (hash + s[i]*power2[i]) % MOD2;
	}
	return hash;
}

ll get_new_hash(ll hash, char prev, int pos, char x){
	hash %= MOD;
	hash = (hash - (prev*power1[pos])) % MOD;
	hash += MOD;
	hash %= MOD;
	hash = (hash + (x*power1[pos])) % MOD;
	hash %= MOD;
	return hash;
}

ll get_new_hash2(ll hash, char prev, int pos, char x){
	hash %= MOD2;
	hash = (hash - (prev*power2[pos])) % MOD2;
	hash += MOD2;
	hash %= MOD2;
	hash = (hash + (x*power2[pos])) % MOD2;
	hash %= MOD2;
	return hash;
}

map<pair<ll,ll>, int> M;

int main(){
    io;
    init();
    int n, m;
    cin >> n >> m;
    for(int i = 0;i < n; i++){
    	string s;
    	cin >> s;
    	ll hash1 = get_hash(s);
    	ll hash2 = get_hash2(s);
    	for(int j = 0;j < s.size(); j++){
    		for(int k = 'a'; k <= 'c'; k++){
    			if(k == s[j])	continue;
    			ll e = get_new_hash(hash1, s[j], j, k);
    			ll f = get_new_hash2(hash2, s[j], j, k);
    			M[{e, f}] = 1;
    		}
    	}
    }
    for(int i = 0;i < m; i++){
		string s;
		cin >> s;
		ll x = get_hash(s);
		ll y = get_hash2(s);
		if(M[{x, y}] > 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
    return 0;
}