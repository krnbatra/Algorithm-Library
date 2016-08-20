#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+5;
vector<int> primes;
int isPrime[MAXN];	//isPrime[i] = 0 indicates i is prime. 
void sieve(int n){
	//if even check itself while calling. This function will only tells wether a number is prime or not(not for even numbers).
	primes.pb(2);
	isPrime[0] = isPrime[1] = 1;
	for(int i = 3; i*i <= n; i+=2){
		if(isPrime[i] == 0){
			primes.pb(i);
			if(i*(ll)1*i <= n){
				for(int j = i*i; j <= n; j += (2*i)){
					isPrime[j] = 1;
				}
			}
		}
	}
}
vector<int> factors;
void factorise(int n){
	sieve(n);
	for(int i = 0;i < primes.size() && (primes[i]*primes[i]) <= n; i++){
		while(n%primes[i] == 0){
			factors.pb(primes[i]);
			n/=primes[i];
		}
	}
	if(n != 1)
		factors.pb(n);
}
/*
	Time Complexity - O(sqrt(N)/ln(sqrt(N)) + log2(N) + n(loglogn))
*/
int main(){
	
	return 0;
}