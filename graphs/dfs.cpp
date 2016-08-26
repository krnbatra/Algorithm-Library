#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define pb push_back

const int MAXN = 1e6+5;
vector<int> adj[MAXN];
int visited[MAXN];

void dfs(int source){
	visited[source] = 1;
	for(int i = 0;i < adj[source].size(); i++){
		if(!visited[adj[source][i]])
			dfs(adj[source][i]);
	}
}


int main(){
	
	return 0;
}