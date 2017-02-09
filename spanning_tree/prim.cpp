/*My First Template :D*/
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

const int MAXN = 1e4+5;
typedef pair<ll, int> PII;
bool vis[MAXN];
int n, m;
vector<pair<ll, int> > adj[MAXN];   // for every vertex store all the edge weight and the adjacent vertex to it

ll prim(int x){
    // start prim from xth vertex
    multiset<ii> S; // acts as min priority queue.
    ll minCost = 0;
    S.insert({0, x});
    while(!S.empty()){
        ii p = *(S.begin());
        S.erase(S.begin());
        x = p.S;
        if(vis[x])
            continue;
        minCost += p.F;
        vis[x] = true;
        for(int i = 0;i < adj[x].size();++i){
            int y = adj[x][i].S;
            if(!vis[y]){
                S.insert(adj[x][i]);
            }
        }
    }
    return minCost;
}

int main(){
    io;
    cin >> n >> m;
    FOR(i, m){
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