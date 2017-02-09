/*My First Template :D*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
 
#define MOD (ll)1000000007
#define pb   push_back
#define EPS 1e-9
#define FOR(i,n)  for(int i = 0;i < n; i++)
#define FORE(i,a,b) for(int i = a;i <= b; i++)
#define tr(container, it)   for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
#define F first
#define S second
#define sp ' '

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}

const int MAXN = 1e5+5;
int parent[MAXN], n, m;
pair<ll, ii> table[MAXN];	// table stores <ll, pair of ints>, weight and in between what n the edge is. 

// numbering of vertices from 1 to n.

void init(){
	FORE(i,1,n){
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
	FOR(i, m){
		int x = table[i].S.F;
		int y = table[i].S.S;
		ll cost = table[i].F;
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
	FOR(i, m){
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