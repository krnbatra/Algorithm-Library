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
bool vis[MAXN];
int n, m;
vector<pair<ll, int> > adj[MAXN];   // for every vertex store all the edge weight and the adjacent vertex to it

ll prim(int x){
    // start prim from xth vertex
    multiset<pair<int, int> > S;
    ll minCost = 0;
    S.insert({0, x});
    while(!S.empty()){
        pair<int, int> p = *(S.begin());
        S.erase(S.begin());
        x = p.second;
        if(vis[x])
            continue;
        minCost += p.first;
        vis[x] = true;
        for(int i = 0; i < adj[x].size(); i++){
            int y = adj[x][i].second;
            if(!vis[y])
                S.insert(adj[x][i]);
        }
    }
    return minCost;
}

int main(){
    io;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y, weight;
        cin >> x >> y >> weight;
        adj[x].pb({weight, y});
        adj[y].pb({weight, x});
    }
    // Selecting any node as the starting node
    ll minCost = prim(1);
    cout << minCost << endl;
    return 0;
}