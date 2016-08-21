#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int MAXN = 1e6+5;
int isPrime[MAXN];	//isPrime[i] = 0 indicates 2*i+1 is prime. 
void sieve(){
	//if even check itself while calling. This function will only tells wether a number is prime or not(not for even numbers).
	//to check a number is prime, check for n>>1.(except 0, 1 and even numbers)
	for(int i = 3; i*i <= MAXN; i+=2){
		if(isPrime[i>>1] == 0){
			if(i*(ll)1*i <= MAXN){
				for(int j = i*i; j <= MAXN; j += (2*i)){
					isPrime[j>>1] = 1;
				}
			}
		}
	}
}

int main(){
	
	return 0;
}
