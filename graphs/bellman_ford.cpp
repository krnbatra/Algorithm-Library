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

vector<pair<ii, int> > edges;	// {{from, to}, weight};
int n, m, dis[1005];

// numbering of vertices from 1 to n.

void init(){
	edges.clear();
	FORE(i,1,n){dis[i]=1e9;}
}

int bellmanFord(int start){
	dis[start] = 0;
    for(int i = 1; i <= n; i++){
        // traverse all the edgess n times and even if the nth time the distance reduces it means there is a negative edges.
        for(int j = 0;j < m; j++){
        	int from = edges[j].F.F;
        	int to = edges[j].F.S;
        	int w = edges[j].S;
        	if(dis[to] > dis[from]+w){
        		if(i == n){
                    // if the reduction happens even on the nth iteration, then there is a negative cycle present.
                    // because each shortest path can contain atmost (n-1) edges.
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
    init();
	FOR(i,m){
    	int a, b, w;
    	cin >> a >> b >> w;
    	edges.pb({{a,b}, w});
    }
    int res = bellmanFord(1);
    if(res == -1)	cout << "Negative cycle found." << endl;
    else
    	FORE(i,1,n)	cout << dis[i] << sp;
    return 0;
}