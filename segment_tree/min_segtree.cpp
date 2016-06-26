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
int tree[400001];
int arr[100001];
void build_tree(int node, int start, int end){
  if(start > end)
    return;
  if(start == end){
    tree[node] = arr[start];
    return;
  }
  build_tree(2*node, start, (start+end)/2);
  build_tree(2*node+1, (start+end)/2+1, end);
  tree[node] = min(tree[2*node], tree[2*node+1]);
}

int min_query(int node, int start, int end, int l, int r){
  if(start > end || start > r || end < l)
    return INT_MAX;
  if(start >= l && end <= r)
    return tree[node];
  return min(min_query(2*node, start, (start+end)/2, l, r), min_query(2*node+1, (start+end)/2+1, end, l, r));
}

void update_query(int node, int start, int end, int l, int r, int value){
  if(start > end || start > r || end < l){
    return;
  }
  if(start==end){
    tree[node]+=value;
    return;
  }
  update_query(2*node, start, (start+end)/2, l, r, value);
  update_query(2*node+1, (start+end)/2+1, end, l, r, value);
  tree[node] = min(tree[2*node], tree[2*node+1]);
}
int main(){
  int q;
  cin>>n>>q;
  FOR(i, n) cin>>arr[i];
  build_tree(1, 0, n-1);
  FOR(i, q){
    char c;
    int l, r;
    cin>>c>>l>>r;
    if(c=='q'){
      cout<<min_query(1, 0, n-1, l-1, r-1)<<endl;
    }else{
      update_query(1, 0, n-1, l-1, l-1, r);
    }
  }
  return 0;   
}
