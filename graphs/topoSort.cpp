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
bool vis[MAXN];
int n, in_degree[MAXN];
vector<int> adj[MAXN], topo;

void topoSort(){
    for(int u = 1; u <= n; u++)
        for(auto v : adj[u])
            indegree[v]++;
    set<int> S;
    for(int i = 1;i <= n; i++){
        if(in_degree[i] == 0){
            S.insert(i);
            vis[i] = true;
        }
    }
    while(!S.empty()){
        int curr = *(S.begin());
        S.erase(S.begin());
        topo.push_back(curr);
        for(auto v : adj[curr]){
            if(!vis[v]){
                indegree[v]--;
                if(indegree[v] == 0){
                    S.insert(v);    
                    vis[v] = 1;
                }
            }
        }
    }
}


int main(){
    io;
    int m;
    cin >> n >> m;
    for(int i = 0;i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    topoSort();
    if(topo.size() != n){
        // topoSort cannot be done. The input graph is not a DAG.
    }
    else{
        for(int i = 0;i < topo.size(); i++){
            cout << topo[i] << sp;
        }
    }
    return 0;
}