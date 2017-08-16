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
int n, m, currTime, disc[MAXN], low[MAXN];
stack<pair<int, int> > stk;

void init(){
    currTime = 0;
    for(int i = 1;i <= n; i++){adj[i].clear();vis[i]=false;AP[i]=false;disc[i]=0;low[i]=INT_MAX;}
}

void print(int u, int v){
    pair<int, int> p = stk.top();
    while(1){
        if(p.first == u && p.second == v)
            break;
        cout << p.first << " " << p.second << endl;
        stk.pop();
        p = stk.top();
    }
    p = stk.top();
    cout << p.first << " " << p.second << endl;
    stk.pop();
}

void dfs(int u, int parent){
    vis[u] = true;
    disc[u] = low[u] = currTime+1;
    int child = 0;
    for(auto v : adj[u]){
        if(v == parent)     continue;
        if(!vis[v]){
            child = child+1;
            currTime++;
            stk.push({u, v});
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(parent == -1 && child > 1){
                print(u, v);
                cout << endl;
            }
            if(parent != -1 && low[v] >= disc[u]){
                print(u, v);
                cout << endl;
            }
        }else if(disc[v] < low[u]){
            // back edge.
            low[u] = disc[v];
            stk.push({u, v});
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
    for(int i = 1;i <= n; i++){
        if(!vis[i]){
            dfs(i, -1);
            while(!stk.empty()){
                pair<int, int> p = stk.top();
                cout << p.first << " " << p.second << endl;
                stk.pop();
            }
        }
    }
    return 0;
}