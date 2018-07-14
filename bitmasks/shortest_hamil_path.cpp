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

const int N = 16;
const int INF = 1e9;

// search for shortest hamiltonian walk, complexity O(n * n * 2^n)

int edges[N][N];
int dp[1 << N][N];

int count(int mask){
	return __builtin_popcount(mask);
}

bool bit(int i, int mask){
	return ((mask >> i) & 1);
}

int main(){
	io;
	int n, m;
	cin >> n >> m;
	
	for(int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		--a;--b;
		edges[a][b] = c;
		edges[b][a] = c;
	}
	
	for(int mask = 0; mask < (1 << n); mask++)
		for(int i = 0; i < n; i++)
			dp[mask][i] = INF;

	for(int mask = 0; mask < (1 << n); mask++){
		for(int i = 0; i < n; i++){
			if(count(mask) == 1 and bit(i, mask)){
				dp[mask][i] = 0;	// only one vertex in hamiltonian subgraph
				// trace(i, mask);
			}
			else if(count(mask) > 1 and bit(i, mask)){
				for(int j = 0; j < n; j++){
					if(edges[i][j] > 0 and bit(j, mask)){
						dp[mask][i] = min(dp[mask][i], dp[mask ^ (1LL << i)][j] + edges[i][j]);
					}
				}
			}
		}
	}
	int ans = INF;
	for(int i = 0; i < n; i++){
		// trace(i, dp[(1 << n) - 1][i]);
		ans = min(ans, dp[(1 << n) - 1][i]);
	}
	cout << ans;
	return 0;
}