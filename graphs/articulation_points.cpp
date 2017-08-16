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

const int MAXN = 1e4+5;
vector<int> adj[MAXN];
bool vis[MAXN], AP[MAXN];
int n, m, currTime;
int disc[MAXN];
int low[MAXN];  // low[i] is the minimum of visited currTime of all vertices which are reachable from i.
vector<pair<int, int> > bridges;

void init(){
    currTime = 0;
    for(int i = 1;i <= n; i++){adj[i].clear();vis[i]=false;AP[i]=false;disc[i]=0;low[i]=INT_MAX;}
}

void dfs(int u, int parent){
    vis[u] = true;
    disc[u] = low[u] = currTime+1;  //since till now i have not explored the children of u all i know is the lowest numbered vertex which can be reached from u is u itself.
    int child = 0;
    for(auto v : adj[u]){
        if(v == parent)     continue;
        if(!vis[v]){
            child = child+1;
            currTime++;
            dfs(v, u);
            //check if subtree rooted at v has a connection to one of the ancestors of u.
            low[u] = min(low[u], low[v]);
            if(low[v] > disc[u]){
                if(u < v)
                    bridges.push_back({u, v});
                else
                    bridges.push_back({v, u});
            }
            if(parent == -1 && child > 1)
                AP[u] = true;
            
            if(parent != -1 && low[v] >= disc[u])
                AP[u] = true;
        }else{
            // back edge.
            low[u] = min(low[u], disc[v]);
        }
    }
}

int main(){
    io;
    cin >> n >> m;
    init();
    for(int i = 0;i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, -1);	//start from any random vertex, make its parent -1.
    
    return 0;
}