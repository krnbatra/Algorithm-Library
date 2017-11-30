#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define M_PI                3.14159265358979323846

const int MAXN = 1e3+5;
vector<int> adj[MAXN], adjReverse[MAXN];
int components[MAXN];   // components[i] indicates to which component vertex i belong to.
int n, m, numberOfComponents, in_degree[MAXN];
bool vis[MAXN];
stack<int> stk;

void init(){
    for(int i = 1;i <= n; i++){
        vis[i] = false;
        adj[i].clear();
        adjReverse[i].clear();
        in_degree[i] = 0;
        components[i] = 0;
        numberOfComponents = 0;
    }
}

void dfs0(int u){
    vis[u] = 1;
    for(auto v : adj[u]){
        if(!vis[v])
            dfs(v);
    }
    stk.push(u);
}

void dfs1(int u){
    vis[u] = 1;
    components[u] = numberOfComponents;
    for(auto v : adjReverse[u]){
        if(!vis[v])
            dfs1(v);
    }
}

void scc(){
    memset(vis, false, sizeof vis);
    while(!stk.empty()){
        int ele = stk.top();
        stk.pop();
        if(!vis[ele]){
            numberOfComponents++;
            dfs1(ele);
        }
    }
}

int main(){
    io;
    cin >> n >> m;
    init();
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adjReverse[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i])
            dfs0(i);
    }
    scc();
    //DAG of SCC is formed calculate indegree of components
    for(int i = 1;i <= n; i++){
        for(int j = 0;j < adj[i].size(); j++){
            int adjacentVertex = adj[i][j];
            if(components[i] != components[adjacentVertex]){
                // in degree of the strongly connected component.
                in_degree[components[adjacentVertex]]++;
            }
        }
    }
    return 0;
}