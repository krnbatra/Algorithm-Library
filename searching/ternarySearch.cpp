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

// applicable only to unimodular functions
double ternarySearch(){
	double minn = a;
	double maxx = b;
	while(maxx-minn > EPS){
		g = minn + (maxx-minn)/3;
		h = minn + 2*(maxx-minn)/3;
		if(f(g) < f(h))
			maxx = h;
		else
			minn = g;
	}
	return (maxx+minn)/2;
}

int main(){
    io;
    
    return 0;
}