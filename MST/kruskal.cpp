#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAXN = 1e5+5;
int parent[MAXN], n, m;
pair<ll, pair<int, int> > table[MAXN];	// table stores <ll, pair of ints>, weight and in between what n the edge is. 

void init(){
	for(int i = 1;i <= n; i++){
		parent[i] = i;
	}
}

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
	for(int i = 0;i < m; i++){
		int x = table[i].second.first;
		int y = table[i].second.second;
		ll cost = table[i].first;
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
	init();
	for(int i = 0;i < m; i++){
		int x, y;
		ll weight;
		cin >> x >> y >> weight;
		table[i] = {weight, {x, y}};
	}
	sort(table, table+m);
	ll minCost = kruskal();
	cout << minCost << endl;
	return 0;
}