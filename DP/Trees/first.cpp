#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
int dp1[MAXN], dp2[MAXN];

void dfs(int u, int parent){
    int sum1 = 0, sum2 = 0;
    for(auto v : adj[u]){
        if(v == parent)     continue;
        dfs(v, u);
        sum1 += dp2[v];
        sum2 += max(dp1[v], dp2[v]);
    }
    dp1[u] = cost[u] + sum1;
    dp2[u] = sum2;
}

int main(){
    io;
    int n;
    cin >> n;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    cout << max(dp1[1], dp2[1]) << endl;
    return 0;
}