/*My First Template :D*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
 
#define MOD                 1000000007LL
#define pb                  push_back
#define EPS                 1e-9
#define FOR(i,n)            for(int i = 0;i < n; i++)
#define FORE(i,a,b)         for(int i = a;i <= b; i++)
#define tr(container, it)   for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl                '\n'
#define F                   first
#define S                   second
#define sp                  ' '
#define M_PI                3.14159265358979323846

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}

const int MAXN = 1e3+5;
vector<int> adj[MAXN];
int residual[MAXN][MAXN];
int from[MAXN];
int n, src, dest;
bool vis[MAXN];

int find_path(){
    queue<int> Q;
    Q.push(src);
    vis[src] = 1;
    memset(vis, false, sizeof vis);
    memset(from, -1, sizeof from);
    int flag = 0;
    while(!Q.empty()){
        int u = Q.front(); Q.pop();
        for(auto v : adj[u]){
            if(!vis[v] && residual[u][v] > 0){
                Q.push(v);
                vis[v] = 1;
                from[v] = u;
                if(v == dest){
                    flag = 1;
                    break;
                }
            }
        }
        if(flag)    break;
    }
    // find min from path
    int current = dest, path_capacity = INT_MAX;
    while(from[current] != -1){
        int prev = from[current];
        path_capacity = min(path_capacity, residual[prev][current]);
        current = prev;
    }
    // update residual
    current = dest;
    while(from[current] != -1){
        int prev = from[current];
        residual[prev][current] -= path_capacity;
        residual[current][prev] += path_capacity;
        current = prev;
    }
    if(path_capacity == INT_MAX)
        return 0;
    return path_capacity;
}

int max_flow(){
    int res = 0;
    while(1){
        int path_capacity = find_path();
        if(path_capacity == 0)
            break;
        res += path_capacity;
    }
    return res;
}

int main(){
    io;
    
    return 0;
}