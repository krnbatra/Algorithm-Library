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

int egcd(int a, int b, int &x, int &y){
	if(b == 0){
		x = 1;
		y = 0;
		return a;
	}else{
		int d = egcd(b, a%b, x, y);
		// x2 and y2 will be values of x and y
		// x2 -= a/b*y 		x1 should be y2 and y1 should be x2
		x -= a/b*y;
		swap(x, y);
		return d;
	}
}

bool linearDiophatine(int A, int B, int C, int &x, int &y){
	int g = gcd(A, B);
	if(C%g != 0)	return false;
	int a = A/g, b = B/g, c = C/g;
	egcd(a, b, x, y);	// solve ax+by = 1
	if(g < 0){
		a *= -1;b *= -1; c *= -1;
	}
	x *= c; y *= c;
	return true;
}

int main(){
    io;
    int x, y;
	linearDiophatine(2, 3, 5, x, y);  
	cout << x << sp << y << endl;
    return 0;
}
