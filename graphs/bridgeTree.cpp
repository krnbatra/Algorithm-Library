/*  My First Template :D*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
 
#define MOD (ll)1000000007
#define pb   push_back
#define EPS 1e-9
#define FOR(i,n)  for(int i = 0;i < n; i++)
#define FORE(i,a,b) for(int i = a;i <= b; i++)
#define tr(container, it)   for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
#define F first
#define S second
#define sp ' '

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}

const int MAXN = 1e5+5;
vector<int> tree[MAXN];     // The bridge edge tree formed from the given graph.
vector<int> adj[MAXN];
int disc[MAXN], low[MAXN], vis[MAXN];
queue<int> Q[MAXN];
int currTime, n, m, cmpno;
map<ii, int> bridge;

void dfs0(int u, int parent){
    vis[u] = true;
    disc[u] = low[u] = currTime++;
    int child = 0;
    FOR(i, (int)adj[u].size()){
        int v = adj[u][i];
        if(v == parent)     continue;
        if(!vis[v]){
            child++;
            dfs0(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > disc[u]){
                bridge[{u, v}] = 1;
                bridge[{v, u}] = 1;
            }
        }else{
            low[u] = min(low[u], disc[v]);
        }
    }
    return;
}

bool isBridge(int u, int v){
    return (bridge[{u, v}] == 1 && bridge[{v, u}] == 1);
}

void dfs1(int u){
    int currcmp = cmpno;
    Q[currcmp].push(u);
    vis[u] = true;
    while(!Q[currcmp].empty()){
        int u = Q[currcmp].front();
        Q[currcmp].pop();
        FOR(i, (int)adj[u].size()){
            int v = adj[u][i];
            if(vis[v])  continue;
            if(isBridge(u, v)){
                cmpno++;
                tree[currcmp].pb(cmpno);
                tree[cmpno].pb(currcmp);
                dfs1(v);
            }else{
                Q[currcmp].push(v);
                vis[v] = true;
            }
        }
    }
    return;
}

int main(){
    io;
    cin >> n >> m;
    FOR(i, m){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs0(1, -1);    // To find bridges  
    memset(vis, false, sizeof vis);
    cmpno = 1;
    dfs1(1);    // To build bridge tree
    FORE(i,1,cmpno){
        FOR(j, tree[i].size()){
            cout << i << sp << tree[i][j] << endl;
        }
    }
    return 0;
}