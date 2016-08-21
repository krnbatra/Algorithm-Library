#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+5;
vector<int> primes;
int isPrime[MAXN];	//isPrime[i] = 0 indicates i is prime. 
void sieve(int n){
	//if even check itself while calling. This function will only tells wether a number is prime or not(not for even numbers).
	primes.push_back(2);
	isPrime[0] = isPrime[1] = 1;
	for(int i = 3; i*i <= n; i+=2){
		if(isPrime[i] == 0){
			primes.push_back(i);
			if(i*(long long)1*i <= n){
				for(int j = i*i; j <= n; j += (2*i)){
					isPrime[j] = 1;
				}
			}
		}
	}
}
vector<int> factors;
int NOD(int n){
	sieve(n);
	int res = 1;
	for(int i = 0;i < primes.size() && (primes[i]*primes[i]) <= n; i++){
		int power = 0;
		while(n%primes[i] == 0){
			n/=primes[i];
			power++;
		}
		power++;
		res = res*power;
	}
	if(n != 1)
		res*=2;
	return res;
}
/*
	Time Complexity - O(sqrt(N)/ln(sqrt(N)) + log2(N) + n(loglogn))
*/

int main(){
	
	return 0;
}
