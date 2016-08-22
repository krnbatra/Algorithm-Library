#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define pb push_back
const int MAXN = 1e6+5;
int minPrime[MAXN];	
void sieve(){
	minPrime[1] = 1;
	for(int i = 2; i*i <= MAXN; i++){
		if(minPrime[i] == 0){
			if(i*(ll)1*i <= MAXN){
				for(int j = i*i; j <= MAXN; j += (i)){
					if(minPrime[j] == 0)
						minPrime[j] = i;
				}
			}
		}
	}
	for(int i = 2;i <= MAXN; i++){
		if(minPrime[i] == 0)
			minPrime[i] = i;
	}
}
/* Time Complexity - O(logN + nloglogN) */
vector<int> factors;
void factorise(int n){
	sieve();
	while(n!=1){
		factors.pb(minPrime[n]);
		n/=minPrime[n];
	}
}



int main(){
	
	return 0;
}
