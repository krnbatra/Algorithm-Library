#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);

int n;
int parent[MAXN];
int size[MAXN];

void init(){
	for(int i = 1;i <= n; i++){
		parent[i] = i;
		size[i] = 1;
	}
}

int root(int i){
	while(i != parent[i]){
		parent[i] = parent[parent[i]];
		i = parent[i];
	}
	return i;
}

bool find(int a, int b){
	return root(a) == root(b);
}

void union1(int a, int b){
	int root_a = root(a);
	int root_b = root(b);
	
	if(root_a == root_b)
		return;
	
	if(size[root_a] < size[root_b]){
		parent[root_a] = root_b;
		size[root_b] += size[root_a];
	}else{
		parent[root_b] = root_a;
		size[root_a] += size[root_b];
	}
}

int main(){
	io;

	return 0;
}