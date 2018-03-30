#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);

const int N = 1e5 + 5;
vector<int> adj[N];

int f[N], g[N], diameter;

void dfs(int u, int parent){
    vector<int> fvalues;
    for(auto v : adj[u]){
        if(v == parent)     continue;
        dfs(v, u);
        fvalues.push_back(f[v]);
    }
    sort(fvalues.begin(), fvalues.end());
    f[u] = 0;
    if((int)fvalues.size() != 0)
        f[u] += fvalues.back();
    if(fvalues.size() >= 2)
        g[u] = 2 + fvalues.back() + fvalues[(int)fvalues.size()-2];
    diameter = max(diameter, max(f[u], g[u]));
}

int main(){
    io;
    
    return 0;
}