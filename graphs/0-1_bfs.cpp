#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl				'\n'
#define trace1(x)			cerr<<#x<<": "<<x<<endl
#define trace2(x, y)		cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)		cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)	cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl

const int N = 1e3 + 5;
vector<pair<int, int> > adj[N];	// {dist, adj vertex}
int dist[N];
int vis[N];
int n, m;

const int INF = (int)1e8;

void bfs_0_1(int src){
	for(int i = 1; i <= n; i++)
		dist[i] = INF;
	dist[src] = 0;
	deque<int> d;
	d.push_front(src);
	while(!d.empty()){
		int u = d.front();
		d.pop_front();
		if(vis[u])	continue;
		vis[u] = 1;
		for(auto p : adj[u]){
			int w = p.first;
			int v = p.second;
			if(dist[u] + w < dist[v]){
				dist[v] = dist[u] + w;
				if(w == 1)
					d.push_back(v);
				else
					d.push_front(v);
			}
		}
	}
}


int main(){
	io;
	cin >> n >> m;
	for(int i = 0;i < m; i++){
		int a, b, w;
		cin >> a >> b >> w;
		adj[a].push_back({w, b});
		adj[b].push_back({w, a});
	}
	bfs_0_1(1);
	for(int i = 1; i <= 7; i++)
		cout << dist[i] << " ";
	cout << endl;
	return 0;
}