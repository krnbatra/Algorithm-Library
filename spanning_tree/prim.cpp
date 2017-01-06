/*My First Template :D*/
#include <bits/stdc++.h>
#include <limits.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
 
#define MOD (ll)1000000007
#define pb   push_back
#define EPS 1e-9
#define FOR(i,n)  for(int i = 0;i < n; i++)
#define FORE(i,a,b) for(int i = a;i <= b; i++)
#define pi(a)   printf("%d\n", a)
#define all(c)  c.begin(), c.end()
#define tr(container, it)   for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define gc getchar_unlocked
#define sdi(a, b)   si(a);si(b)
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
#define F first
#define S second
#define FILL(arr, val)  memset(arr, val, sizeof(arr))
#define read(arr, n)    for(int i = 0;i < n; i++)cin>>arr[i];
#define sp ' '

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}

void si(int &x){
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}


const int MAXN = 1e4+5;
typedef pair<ll, int> PII;
bool vis[MAXN];
int nodes;
vector<pair<ll, int> > adj[MAXN];   //for every vertex store all the edge weight and the adjacent vertex to it

ll prim(int x){
    //start prim from xth vertex
    priority_queue<PII, vector<PII>, greater<PII> > Q;    //minimum priority queue
    ll minCost = 0;
    Q.push({0, x});
    while(!Q.empty()){
        PII p = Q.top();
        Q.pop();
        x = p.S;
        if(vis[x] == true)
            continue;
        minCost += p.F;
        vis[x] = true;
        for(int i = 0;i < adj[x].size();++i){
            int y = adj[x][i].S;
            if(vis[y] == false)
                Q.push(adj[x][i]);
        }
    }
    return minCost;
}

int main(){
    io;
    int edges;
    cin >> nodes >> edges;
    for(int i = 0;i < edges;++i){
        int x, y;
        ll weight;
        cin >> x >> y >> weight;
        adj[x].pb({weight, y});
        adj[y].pb({weight, x});
    }
    // Selecting 1 as the starting node
    ll minCost = prim(1);
    cout << minCost << endl;
    return 0;
}