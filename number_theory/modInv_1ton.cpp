#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define pb push_back

int inv[10];
int n, m;
//Time Complexity O(n).
void precalc(){
	inv[1] = 1;
	for(int i = 2;i <= n; i++){
		inv[i] = (-(m/i)*inv[m%i])%m;
		inv[i] += m;
	}
}

int main(){
	n = 4, m = 5;
	precalc();
	cout<<inv[4]<<endl;
	return 0;
}