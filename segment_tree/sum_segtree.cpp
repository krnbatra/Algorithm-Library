#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAXN = 1e5+5; 
int n;
int tree[4*MAXN];
int arr[MAXN];

// O(n)
void build(int node, int start,  int end){
	if(start > end)		return;

	if(start==end){
		tree[node] = arr[start];
		return;
	}
	int mid = (start+end) >> 1;
	int left = node << 1, right = left + 1;
	build(left, start, mid);
	build(right, mid + 1, end);
	tree[node] = tree[left] + tree[right];
}

// O(log(n))
int query(int node, int start, int end, int l, int r){
	if(start > end || start > r || end < l)
		return 0; 
	if(start >= l && end <= r)
		return tree[node];
	int mid = (start+end) >> 1;
	int left = node << 1, right = left + 1;
	return query(left, start, mid, l, r) + query(right, mid + 1, end, l, r);
}

// O(log(n))
void updateIndex(int node, int start, int end, int idx, int value){
	if(start == end){
		tree[node] += value;
		arr[idx] += value;
	}else{
		int mid = (start+end) >> 1;
		int left = node << 1, right = left + 1;
		if(idx >= start && idx <= mid)
			updateIndex(left, start, mid, idx, value);
		else
			updateIndex(right, mid + 1, end, idx, value);
		tree[node] = tree[left] + tree[right];
	}
}

// O(n)
void update(int node, int start, int end, int l, int r, int value){
	//no overlap of the l to r segment on the current segment
	if(start > end || start > r || end < l)
		return;
	if(start == end){
		tree[node] += value;
		arr[start] += value;
		return;
	}
	int mid = (start+end) >> 1;
	int left = node << 1, right = left + 1;
	update(left, start, mid, l, r, value);
	update(right, mid + 1, end, l, r, value);
	tree[node] = tree[left] + tree[right]; 
}

int main(){
	io;
	
	return 0;
}
