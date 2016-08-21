#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int MAXN = 1e6+5;
int isPrime[MAXN];	//isPrime[i] = 0 indicates i is prime. 
void sieve(){
	//if even check itself while calling. This function will only tells wether a number is prime or not(not for even numbers).
	isPrime[0] = isPrime[1] = 1;
	for(int i = 3; i*i <= MAXN; i+=2){
		if(isPrime[i] == 0){
			if(i*(ll)1*i <= MAXN){
				for(int j = i*i; j <= MAXN; j += (2*i)){
					isPrime[j] = 1;
				}
			}
		}
	}
}

int main(){
	
	return 0;
}
