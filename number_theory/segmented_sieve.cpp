#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define pb push_back

const int MAXN = 1e6;
vector<int> primes;
int isPrime[MAXN];	//isPrime[i] = 0 indicates i is prime. 
void sieve(){
	//if even check itself while calling. This function will only tells wether a number is prime or not(not for even numbers).
	isPrime[0] = isPrime[1] = 1;
	primes.pb(2);
	for(int i = 3; i <= MAXN; i+=2){
		if(isPrime[i] == 0){
			primes.pb(i);
			if(i*(ll)1*i <= MAXN){
				for(int j = i*i; j <= MAXN; j += (2*i)){
					isPrime[j] = 1;
				}
			}
		}
	}
}

const int SIZE = (int)1e6+1; 	//define size to be max(B-A+1)
int arr[SIZE];
void segmentedSieve(int a, int b){
	memset(arr, 0, sizeof(arr));
	if(a == 1)	a++;
	int sqrtn = sqrt(b);
	//arr[0] represents a
	for(int i = 0;i < primes.size() && primes[i] <= sqrtn; i++){
		int p = primes[i];
		int j = p*p;

		if(j < a)	j = ((a+p-1)/p)*p;	//j = ceil(a/p)*p
		for(; j <= b; j+=p)
			arr[j-a] = 1;
	}
	int res = 0;
	for(int i = a; i<= b; i++){
		if(arr[i-a] == 0)
			pi(i);
	}
	return;
}


int main(){
	
	return 0;
}