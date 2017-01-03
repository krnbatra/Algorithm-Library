#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define pb push_back

int modInv ( int a, int m ) {
    int x, y;
    ext_gcd( a, m, &x, &y );
 
    ///Process x so that it is between 0 and m-1
    x %= m;
    if ( x < 0 ) x += m;
    return x;
}

int main(){
	
	return 0;
}