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
const int INF = 1000000000;

struct edge{
    int a, b, cap, flow;
};

int n, s, t, d[MAXN], ptr[MAXN];
vector<edge> e;
vector<int> g[MAXN];

void add_edge(int a, int b, int cap){
    edge e1 = {a, b, cap, 0};
    edge e2 = {b, a, 0, 0};
    g[a].push_back(e.size());   // storing index of the edge
    e.push_back(e1);
    g[b].push_back(e.size());
    e.push_back(e2);
}

bool bfs(){
    queue<int> q;
    q.push(s);
    memset(d, -1, sizeof d);
    d[s] = 0;
    while(!q.empty()){
        int u = q.front();q.pop();
        for(auto id : g[u]){
            int v = e[id].b;
            if(d[v] == -1 && e[id].flow < e[id].cap){
                q.push(v);
                d[v] = d[u] + 1;
            }
        }
    }
    return d[t] != -1;
}

int dfs(int v, int flow){
    if(flow == 0)   return 0;
    if(v == t)  return flow;
    for(; ptr[v] < (int)g[v].size(); ptr[v]++){
        int id = g[v][ptr[v]];
        int to = e[id].b;
        if(d[to] != d[v] + 1)   continue;
        int pushed = dfs(to, min(flow, e[id].cap - e[id].flow));
        if(pushed){
            e[id].flow += pushed;
            e[id^1].flow -= pushed;
            return pushed;
        }
    }
    return 0;
}

int dinic(){
    int flow = 0;
    while(1){
        if(!bfs)    break;
        memset(ptr, 0, sizeof ptr);
        while(int pushed = dfs(s, INF))
            flow += pushed;
    }
    return flow;
}

int main(){
    io;
    
    return 0;
}