#include <bits/stdc++.h>
using namespace std;

int SNOD(int n){
	//O(n)	approach
	int res = 0;
	for(int i = 1;i <= n; i++){
		res += n/i;
	}
	return res;
}

int main(){
	
	return 0;
}
