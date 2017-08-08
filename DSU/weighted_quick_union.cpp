/*
	Time complexity - 
						find(a, b)	O(logn)
						union(a, b)	O(logn)

*/
/*Let's get high :D*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define M_PI                3.14159265358979323846

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}

const int MAXN = 1e5+5;
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
	while(i != parent[i])
		i = parent[i];
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