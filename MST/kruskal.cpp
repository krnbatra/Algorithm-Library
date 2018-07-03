#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif


const int N = 2e5 + 5;
int parent[N], n, m;
pair<ll, pair<int, int> > edges[N]; // edges stores <ll, pair of ints>, weight and in between what n the edge is. 

int root(int x){
    while(parent[x] != x){
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

void union1(int x, int y){
    int root_a = root(x);
    int root_b = root(y);
    parent[root_a] = root_b;
}

ll kruskal(){
    ll minCost = 0;
    for(int i = 0; i < m; i++){
        int x = edges[i].second.first;
        int y = edges[i].second.second;
        ll cost = edges[i].first;
        //check if the selected edge makes a cycle or not.
        if(root(x) != root(y)){
            minCost += cost;
            union1(x, y);
        }
    }
    return minCost;
}

int main(){
    io;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        parent[i] = i;
    for(int i = 0; i < m; i++){
        int x, y;
        ll weight;
        cin >> x >> y >> weight;
        edges[i] = {weight, {x, y}};
    }
    sort(edges, edges + m);
    ll minCost = kruskal();
    cout << minCost << endl;
    return 0;
}