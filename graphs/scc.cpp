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

const int MAXN = 1e3+5;
vector<int> adj[MAXN], adjReverse[MAXN];
int components[MAXN];   // components[i] indicates to which component vertex i belong to.
int n, m, numberOfComponents,in_degree[MAXN];
bool vis[MAXN];
stack<int> stk;

// numbering of vertices from 1 to n.

void init(){
    FORE(i,1,n){vis[i] = false;adj[i].clear();adjReverse[i].clear();in_degree[i]=0;components[i]=0;numberOfComponents=0;}
}

void dfs(int src){
    vis[src] = 1;
    FOR(i, adj[src].size()){
        if(!vis[adj[src][i]]){
            dfs(adj[src][i]);
        }
    }
    //ordering the vertices according to the finish times, the vertex finishing last will be at the top of stack.
    stk.push(src);
}

void dfsModify(int src){
    vis[src] = 1;
    components[src] = numberOfComponents;
    FOR(i, adjReverse[src].size()){
        if(!vis[adjReverse[src][i]]){
            dfsModify(adjReverse[src][i]);
        }
    }
}

void scc(){
    FORE(i,1,n) vis[i] = false;
    while(!stk.empty()){
        int ele = stk.top();
        stk.pop();
        if(!vis[ele]){
            numberOfComponents++;
            dfsModify(ele);
        }
    }
}

int main(){
    io;
    cin >> n >> m;
    init();
    FOR(j, m){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adjReverse[b].pb(a);
    }
    FORE(i,1,n){
        if(!vis[i]){
            dfs(i);
        }
    }
    scc();
    //DAG of SCC is formed calculate indegree of components
    FORE(i,1,n){
        FOR(j, adj[i].size()){
            int adjacentVertex = adj[i][j];
            if(components[i] != components[adjacentVertex]){
                // in degree of the strongly connected component.
                in_degree[components[adjacentVertex]]++;
            }
        }
    }
    int countZeroIndegree = 0;
    int componentWithIndegreeZero = -1;
    FORE(i,1,numberOfComponents){
        if(in_degree[i] == 0){
            countZeroIndegree++;
            componentWithIndegreeZero = i;
        }
    }
    if(countZeroIndegree > 1 || numberOfComponents == 0 || countZeroIndegree == 0){
        cout << 0 << endl;
    }else{
        int ans = 0;
        FORE(i,1,n){
            if(components[i] == componentWithIndegreeZero){
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}