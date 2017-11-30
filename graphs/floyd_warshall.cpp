#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dist[1000][1000];
int weight[1000][1000];
int n;

void floyd_warshall(){
	for(int i = 0;i < n; i++)
		for(int j = 0;j < n; j++)
			dist[i][j] = i == j ? 0 : weight[i][j];
		
	for(int k = 0;k < n; k++){	//shortest path to reach from i to j if we're allowed to travel through the vertices 0,1...k
		for(int i = 0;i < n; i++){
			for(int j = 0;j < n; j++){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}

int main(){
    io;
	    
    return 0;
}