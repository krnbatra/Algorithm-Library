/*
	Time Complexity - O((V+E)logV)
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4+5;
typedef pair<long long, int> PII;
bool marked[MAXN];
vector<PII> adj[MAXN];

long long prim(int x){
	priority_queue<PII, vector<PII>, greater<PII> > Q;	//minimum priority queue
	long long minimumCost = 0;
	PII p;
	Q.push(make_pair(0, x));
	while(!Q.empty()){
		p = Q.top();
		Q.pop();
		x = p.second;
		if(marked[x] == true)
			continue;
		minimumCost += p.first;
		marked[x] = true;
		for(int i = 0;i < adj[x].size(); i++){
			if(!marked[adj[x][i]])
				Q.push(adj[x][i]);
		}
	}
	return minimumCost;
}

int main(){
	int nodes, edges, x, y;
	long long weight, minimumCost;
	cin>>nodes>>edges;
	for(int i = 0;i < edges; i++){
		cin>>x>>y>>weight;
		adj[x].push_back(make_pair(weight, y));
		adj[y].push_back(make_pair(weight, x));
	}
	minimumCost = prim(1);
	cout<<minimumCost<<endl;
	return 0;
}