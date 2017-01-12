#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define pb push_back

int visited[100005];
vector<int> adj[100005];
int depth[100005];

void bfs(int source){
	queue<int> q;
	q.push(souce);
	visited[source] = 1;
	depth[source] = 1;
	int ans = 0;
	while(!q.empty()){
		int node = q.front();
		int curr_level = depth[node];
		q.pop();
		for(int i = 0;i < adj[node].size(); i++){
			if(!visited[adj[node][i]]){
				depth[adj[node][i]] = curr_level+1;
				q.push(adj[node][i]);
				visited[adj[node][i]] =  1;		//since a vertex could be pushed by multiple adjacent vertices hence vis should be set to 1 only when pushing.
			}
		}
	}
}

int main(){
	
	return 0;
}