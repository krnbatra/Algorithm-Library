#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;
int parent[MAXN], nodes, edges;
pair<long long, pair<int, int> > p[MAXN];

void initialize(){
	for(int i = 0;i <= nodes; i++){
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

long long kruskal(pair<long long, pair<int, int> > p[]){
	int x, y;
	long long cost, minimumCost = 0;
	for(int i = 0;i < edges; i++){
		x = p[i].second.first;
		y = p[i].second.second;
		cost = p[i].first;
		//check if the selected edge makes a cycle or not.
		if(root(x)!=root(y)){
			minimumCost += cost;
			union1(x, y);
		}
	}
	return minimumCost;
}

int main(){
	int x, y;
	long long weight, cost, minimumCost;
	cin>>nodes>>edges;
	initialize();
	for(int i = 0;i < edges; i++){
		cin>>x>>y>>weight;
		p[i] = make_pair(weight, make_pair(x, y));
	}
	sort(p, p+edges);
	minimumCost = kruskal(p);
	cout<<minimumCost<<endl;
	return 0;
}