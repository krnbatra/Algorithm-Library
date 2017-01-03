#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define pb push_back


/*use when there are large no. of quereis. */
/*used very rarely*/
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
int eulerPhi(int n){
	int res = n;
	for(int i = 0;i < primes.size() && (primes[i]*primes[i]) <= n; i++){
		if(n%primes[i] == 0){
			while(n%primes[i] == 0){
				n/=primes[i];
			}
			res/=primes[i];
			res*=(primes[i]-1);
		}
	}
	if(n != 1){
		res/=n;
		res*=(n-1);
	}
        return res;
}
/*
	Time Complexity - O(sqrt(N)/ln(sqrt(N)) + log2(N) + n(loglogn))
*/

int main(){
	sieve(n);
    cout<<eulerPhi(8)<<endl; 
	return 0;
}
