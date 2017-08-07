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

int dist[1000][1000];
int weight[1000][1000];
int n;

void floyd_warshall(){
	for(int i = 0;i < n; i++)
		for(int j = 0;j < n; j++)
			dist[i][j] = i == j ? 0 : weight[i][j];
		
	for(int k = 0;k < n; k++){	//shortest path to reach from i to j if we're allowed to travel through the vertices 0,1...k
		for(int i = 0;i < n; i++){
			for(int j = 0;j < n; j++){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}

int main(){
    io;
	    
    return 0;
}