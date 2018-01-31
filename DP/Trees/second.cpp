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
vector<int> adj[MAXN];

int f[MAXN], g[MAXN], diameter;

void dfs(int u, int parent){
    vector<int> fvalues;
    for(auto v : adj[u]){
        if(v == parent)     continue;
        dfs(v, u);
        fvalues.push_back(f[v]);
    }
    sort(fvalues.begin(), fvalues.end());
    f[u] = 1;
    if((int)fvalues.size() != 0)
        f[u] += fvalues[(int)fvalues.size()-1];
    if(fvalues.size() >= 2)
        g[u] = 2 + fvalues[(int)fvalues.size()-1] + fvalues[(int)fvalues.size()-2];
    diameter = max(diameter, max(f[u], g[u]));
}

int main(){
    io;
    
    return 0;
}