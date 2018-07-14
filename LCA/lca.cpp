#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);

const int N = 1e5 + 5;
const int LOG = log2(N) + 1;

int n;
vector<int> adj[N];
int depth[N], par[N][LOG];

// <O(NlogN), O(logN)>

// par[i][j] is 2^jth ancestor of i

void dfs(int u, int parent = -1){
	par[u][0] = parent;
	if(parent != -1)
		depth[u] = depth[parent] + 1;
	for(int i = 1; i < LOG; i++){
		if(par[u][i - 1] != -1)
			par[u][i] = par[ par[u][i - 1] ][i - 1];
    }1
	for(auto v : adj[u]){
		if(v == parent)	continue;
		dfs(v, u);
	}
}

int lca(int u, int v){
	if(depth[u] < depth[v])	swap(u, v);
	// depth[u] >= leve[v]
	int diff = depth[u] - depth[v];	// make those jumps which bits are set in diff 
	for(int i = LOG - 1; i >= 0; i--){
		// if we have the opportunity to jump 2^i upwards we jump
		if(diff & (1 << i))
			u = par[u][i];
	}
	if(u == v)
		return u;
	// depths of both u and v are equal now
	// sort of binary lifting going up by highest exponent of 2
	for(int i = LOG - 1; i >= 0; i--){
		if(par[u][i] != -1 && par[u][i] != par[v][i]){
			u = par[u][i];
			v = par[v][i];
		}
	}
	return par[u][0];
}

int kth(int n, int k){
	for(int i = 0; i < LOG; i++){
		if(k & (1 << i))
			n = par[n][i];
	}
	return n;
}

int main(){
    io;
    cin >> n;
    for(int i = 1; i < n; i++){
    	int a, b;
    	cin >> a >> b;
    	adj[a].push_back(b);
    	adj[b].push_back(a);
    }
    memset(par, -1, sizeof par);
    dfs(1);
    cout << lca(1, 3) << endl;
    return 0;
}