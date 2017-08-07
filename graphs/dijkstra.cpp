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

vector<pair<int, int> > adj[MAXN];   //{dist, adjacent_vertex}
ll dist[MAXN];
bool vis[MAXN];
int n, m, st, finish;

void init(){
    for(int i = 1;i <= n; i++){
        adj[i].clear();
        dist[i] = (int)1e6;
        vis[i] = false;
    }
}

void dijkstra(){
    dist[st] = 0;
    multiset<pair<int, int> > S;
    S.insert({0,st});
    while(!S.empty()){
        pair<int, int> p = *(S.begin());
        S.erase(S.begin());
        int u = p.second;
        if(vis[u])     //according to the algorithm the distance to the visited vertices is minimal.
            continue;
        vis[u] = true;
        int adjacent_vertex, weight;
        for(auto adjacent_pair : adj[u]){
            adjacent_vertex = adjacent_pair.second;
            weight = adjacent_pair.first;
            if(dist[u] + weight < dist[adjacent_vertex]){
                dist[adjacent_vertex] = dist[u] + weight;
                S.insert({dist[adjacent_vertex], adjacent_vertex}); //a vertex can be pushed multiple times do not mark vis as true while pushing instead mark it while popping out.
            }
        }
    }
}

int main(){
    io;
    cin >> n >> m >> st >> finish;
    init();
    for(int i = 0;i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({w, b});
        adj[b].push_back({w, a});
    }
    dijkstra();
    if(dist[finish] == (int)1e6)
        cout << "NONE" << endl;
    else
        cout << dist[finish] << endl;
    return 0;
}