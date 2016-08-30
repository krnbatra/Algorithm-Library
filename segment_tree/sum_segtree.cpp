#include <bits/stdc++.h>
#include <limits.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
 
#define MOD (ll)1000000007
#define pb  push_back
#define EPS 1e-9
#define FOR(i, n) for(int i = 0;i < n; i++)
#define all(c) c.begin(), c.end()
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it!=container.end(); it++)
#define present(container, element) (container.find(element)!=container.end())    //valid for sets and maps.
#define cpresent(container, element) (find(all(container), element)!=container.end()) //valid for all the containers
 
template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}
 
int t;
int n;
int tree[4000];
int arr[1000];

//build has time complexity of O(n)
void build(int node, int start,  int end){
  if(start > end)
    return;
  if(start==end){
    //Leaf node.
    tree[node] = arr[start];
    return;
  }
  //Recurse on the left child.
  int mid = (start+end)/2;
  build(2*node, start, mid);
  //Recurse on the right child.
  build(2*node+1, mid+1, end);
  //Internal node will have the sum of both its children.
  tree[node] = tree[2*node] + tree[2*node+1];
}

int query_sum(int node, int start, int end, int l, int r){
  if(start > end || start > r || end < l)
    return 0; 
    //complete overlap
  if(l <= start && end <= r)
    return tree[node];
    //partial overlap
  int mid = (start+end)/2;
  return query_sum(2*node, start, mid, l, r) + query_sum(2*node+1, mid+1, end, l, r);
}

void updateIndex(int node, int start, int end,int idx, int value){
  if(start == end){
    tree[node]+=value;
    arr[idx]+=value;
  }else{
    int mid = (start+end)/2;
    if(start <= idx && idx <= mid){
      updateIndex(2*node, start, mid, idx, value);
    }else{
      updateIndex(2*node+1, mid+1, end, idx, value);
    }
    tree[node] = tree[2*node]+tree[2*node+1];
  }
}


void update(int node, int start, int end, int l, int r, int value){
  //increase values from l to r by value
  //no overlap of the l to r segment on the current segment
  if(start > end || start > r || end < l)
    return;
  if(start==end){
    //Leaf node
    tree[node]+=value;
    return;
  }
  int mid = (start+end)/2;
  update(2*node, start, mid, l, r, value);
  update(2*node+1, mid+1, end, l, r, value);
  tree[node] = tree[2*node] + tree[2*node+1]; 
}

int main(){
  for(int i = 0;i < 6; i++){
    arr[i] = i;
  }
  n = 6;
  int seg_tr_size = 2*pow(2,(int)ceil(log2(n)));
  build(1, 0, n-1);
  update(1, 0, n-1, 1, 3, 3);
  cout<<query_sum(1, 0, n-1, 2, 4);
  return 0;
}
