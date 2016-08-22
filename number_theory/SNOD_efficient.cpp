#include <bits/stdc++.h>
using namespace std;

int SNOD(int n){
	//O(sqrt(n))	approach
	int res = 0;
	int u = sqrt(n);
	for(int i = 1;i <= u; i++){
		res += n/i - i;
	}
	res*=2;
	res+=u;
	return res;
}

int main(){
	
	return 0;
}
