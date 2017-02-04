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

vector<pair<ii, int> > edge;	//{{to, from}, weight};
int dis[1005];
int n, m;

void initialize(){
	edge.clear();
	FOR(i,n){dis[i]=1e9;}
}

int bellmanFord(int start){
	dis[start] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0;j < m; j++){
        	int from = edge[j].F.F;
        	int to = edge[j].F.S;
        	int w = edge[j].S;
        	if(dis[to] > dis[from]+w){
        		if(i == n){
        			return -1;
        		}
        		dis[to] = dis[from]+w;
        	}
        }
    }
}

int main(){
    io;
    cin >> n >> m;
    initialize();
	FOR(i,m){
    	int a, b, w;
    	cin >> a >> b >> w;
    	edge.pb({{a,b}, w});
    }
    int res = bellmanFord(1);
    if(res == -1)	cout << "Negative cycle found." << endl;
    else
    	FORE(i,2,n)	cout << dis[i] << sp;
    return 0;
}