#include <bits/stdc++.h>
using namespace std;
#define pb push_back
/*
	Time Complexity - O(sqrtN)
*/
vector<int> factors;
void factorise(int n){
	for(int i = 2; i*i <= n; i++){
		while(n%i == 0){
			n/=i;
			factors.pb(i);
		}
	}
	if(n != 1)
		factors.pb(n);
}

int main(){
	
	return 0;
}
