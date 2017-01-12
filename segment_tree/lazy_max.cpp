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

const int MAXN = 1e5+5; 
int t;
int n;
int arr[MAXN];
int tree[4*MAXN];
int lazy[4*MAXN];

void build_tree(int node, int start, int end){
  if(start > end)
    return;
  if(start==end){
    tree[node] = arr[start];
    return;
  }
  build_tree(start, (start+end)/2, 2*node);
  build_tree((start+end)/2+1, end, 2*node+1);
  tree[node] = max(tree[2*node], tree[2*node+1]);  
}

void update_tree(int node, int start, int end, int l, int r, int value){
  if(lazy[node] != 0){
    tree[node]+=lazy[node];
    if(start!=end){
      lazy[2*node]+=lazy[node];
      lazy[2*node+1]+=lazy[node];
    }
    lazy[node] = 0;
  }
  if(start > end || start > r || end < l)
    return;
  if(start >= l && end <= r){
    tree[node]+=value;
    if(start != end){
      lazy[2*node]+=value;
      lazy[2*node+1]+=value;
    }
    return;
  }
  update_tree(2*node, start, (start+end)/2, l, r, value);
  update_tree(2*node+1, (start+end)/2+1, end, l, r, value);
  tree[node] = max(tree[2*node], tree[2*node+1]);
}
int max_query(int node, int start, int end, int l, int r){
  if(start > end || start > r || end < l)
    return INT_MIN;

  if(lazy[node]!=0){
    tree[node]+=lazy[node];
    if(start != end){
      lazy[2*node]+=lazy[node];
      lazy[2*node+1]+=lazy[node];
    }
    lazy[node]=0;
  }
  
  if(start >= l && end <= r){
    return tree[node];
  } 
  return max(max_query(2*node, start, (start+end)/2, l, r), max_query(2*node+1, (start+end)/2+1,end, l, r));
}
int main(){

  return 0;   
}
