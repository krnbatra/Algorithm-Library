#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAXN = 1e5+5;

// applicable only to unimodular functions
double ternarySearch(){
	double minn = a;
	double maxx = b;
	while(maxx-minn > EPS){
		double g = minn + (maxx-minn)/3;
		double h = minn + 2*(maxx-minn)/3;
		if(f(g) < f(h))		// have to write f(), calculates minima
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