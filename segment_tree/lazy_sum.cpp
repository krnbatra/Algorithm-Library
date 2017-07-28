/*My First Template :D*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
 
#define MOD         1000000007LL
#define pb          push_back
#define EPS         1e-9
#define FOR(i,n)      for(int i = 0;i < n; i++)
#define FORE(i,a,b)     for(int i = a;i <= b; i++)
#define tr(container, it)   for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define io          ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl        '\n'
#define F           first
#define S           second
#define sp          ' '
#define M_PI          3.14159265358979323846

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}

const int MAXN = 1e5+5; 
int t;
int n;
int tree[4*MAXN];
int arr[MAXN];
int lazy[4*MAXN];

void build(int node, int start, int end){
	if(start > end)
		return;
	
	if(start == end){
		tree[node]=arr[start];
		return;
	}
	
	int mid = (start+end) >> 1;
	int left = node << 1, right = left+1;
	build(left, start, mid);
	build(right, mid+1, end);
	tree[node] = tree[left] + tree[right];
}

void update_range_lazy(int node, int start, int end, int l, int r, int value){
	if(lazy[node] != 0){
		//This node needs to be updated
		tree[node] += (end-start+1)*lazy[node];
		if(start != end){
			lazy[2*node] += lazy[node];
			lazy[2*node+1] += lazy[node];
		}
		lazy[node] = 0;
	}
	
	if(start > end || start > r || end < l)
		return;
	
	if(start >= l && end <= r){
		tree[node] += (end-start+1)*value;
		if(start != end){
			lazy[2*node] += value;
			lazy[2*node+1] += value;
		}
		return;
	}
	int mid = (start+end) >> 1;
	update_range_lazy(2*node, start, mid, l, r, value);
	update_range_lazy(2*node+1, mid+1, end, l, r, value);
	tree[node] = tree[2*node]+tree[2*node+1];
}

int query_lazy(int node, int start, int end,int l, int r){
	
	if(start > end || start > r || end < l)
		return 0;
	
	if(lazy[node] != 0){
		tree[node] += (end-start+1)*lazy[node];   //total nodes updated will be (end-start+1) that's why it's factor will not come in case of max and min.
		if(start != end){
			lazy[2*node] += lazy[node];
			lazy[2*node+1] += lazy[node];
		}
		lazy[node] = 0;
	}

	if(start >= l && end <= r){
		return tree[node];
	}
	
	return query_lazy(2*node, start, (start+end)/2, l, r)+query_lazy(2*node+1, (start+end)/2+1, end, l, r);
}

int main(){
     
  return 0;   
}