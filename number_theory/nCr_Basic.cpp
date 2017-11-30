#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll nCr(int n, int r){
	if(r == 0)	return 1;
	return nCr(n-1, r-1) * n/r;
}

int main(){
    io;
    cout << nCr(5, 3) << endl;
    return 0;
}
