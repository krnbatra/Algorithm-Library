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
vector<int> adj[MAXN], tree[MAXN];     // The bridge edge tree formed from the given graph.
int disc[MAXN], low[MAXN], vis[MAXN];
queue<int> Q[MAXN];
int currTime, n, m, cmpno = 1;
map<pair<int, int>, int> bridge;

void dfs0(int u, int parent){
    vis[u] = true;
    disc[u] = low[u] = currTime++;
    for(auto v : adj[u]){
        if(v == parent)     continue;
        if(!vis[v]){
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
        for(auto v : adj[u]){
            if(vis[v])  continue;
            if(isBridge(u, v)){
                cmpno++;
                tree[currcmp].push_back(cmpno);
                tree[cmpno].push_back(currcmp);
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
    for(int i = 0;i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs0(1, -1);    // To find bridges  
    memset(vis, false, sizeof vis);
    dfs1(1);    // To build bridge tree
    for(int i = 1;i <= cmpno; i++){
        for(int j = 0;j < tree[i].size(); j++)
            cout << i << " " << tree[i][j] << endl;
    }
    return 0;
}