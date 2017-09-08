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
int tree[4*MAXN], arr[MAXN], lazy[4*MAXN];

void build(int node, int start, int end){
	if(start > end)
		return;
	
	if(start == end){
		tree[node] = arr[start];
		return;
	}
	
	int mid = (start+end) >> 1;
	int left = node << 1, right = left + 1;
	build(left, start, mid);
	build(right, mid + 1, end);
	tree[node] = tree[left] + tree[right];
}

void update_range_lazy(int node, int start, int end, int l, int r, int value){
	int left = node << 1, right = left + 1;
	if(lazy[node] != 0){
		//This node needs to be updated
		tree[node] += (end-start+1)*lazy[node];
		if(start != end){
			lazy[left] += lazy[node];
			lazy[right] += lazy[node];
		}
		lazy[node] = 0;
	}
	
	if(start > end || start > r || end < l)
		return;
	
	if(start >= l && end <= r){
		tree[node] += (end-start+1) * value;
		if(start != end){
			lazy[left] += value;
			lazy[right] += value;
		}
		return;
	}
	int mid = (start+end) >> 1;
	update_range_lazy(left, start, mid, l, r, value);
	update_range_lazy(right, mid + 1, end, l, r, value);
	tree[node] = tree[left] + tree[right];
}

int query_lazy(int node, int start, int end,int l, int r){
	int left = node << 1, right = left + 1;	
	if(lazy[node] != 0){
		tree[node] += (end-start+1)*lazy[node];   //total nodes updated will be (end-start+1) that's why it's factor will not come in case of max and min.
		if(start != end){
			lazy[left] += lazy[node];
			lazy[right] += lazy[node];
		}
		lazy[node] = 0;
	}

	if(start > end || start > r || end < l)
		return 0;

	if(start >= l && end <= r)
		return tree[node];
	
	int mid = (start + end) >> 1;

	return query_lazy(left, start, mid, l, r) + query_lazy(right, mid + 1, end, l, r);
}

int main(){
     
  return 0;   
}