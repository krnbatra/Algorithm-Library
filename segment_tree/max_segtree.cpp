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
int seg[1000];

void build_tree(int arr[], int a, int b, int node){
  if(a > b)
    return;
  if(a==b){
    seg[node]=arr[a];
    return;
  }
  build_tree(arr, a, (a+b)/2, 2*node);
  build_tree(arr, (a+b)/2+1, b, 2*node+1);
  seg[node] = max(seg[2*node], seg[2*node+1]);
}

int max_query(int node, int ss, int se, int l, int r){
  if(ss > se || ss > r || se < l)
    return INT_MIN;
  if(ss >= l && se <= r)
    return seg[node];
  return max(max_query(2*node, ss, (ss+se)/2, l, r), max_query(2*node+1, (ss+se)/2+1, se, l, r));
}

int main(){
  int arr[] = {1, 3, 5, 7, 9, 11};
  build_tree(arr, 0, 5, 1);
  cout<<max_query(1, 0, 5, 1, 3);     
  return 0;   
}
