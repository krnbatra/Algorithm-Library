#include <bits/stdc++.h>
#include <limits.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
 
#define MOD (ll)1000000007

/*calculating phi(n) where a <= n <= b && a, b <= 1e14 and b-a <= 1e5*/
const int MAXN = 1e7;
vector<int> primes;
int isPrime[MAXN+1];    //isPrime[i] = 0 indicates i is prime. 
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

const int SIZE = (int)1e5+1;     //define size to be max(B-A+1)
ll r[SIZE];
ll phi[SIZE];
void segmentedSieve(ll a, ll b){
    for(int i = 0;i < SIZE; i++){
        r[i] = a+i;
        phi[i] = a+i;
    }
    for(int i = 0;i < primes.size(); i++){
        int p = primes[i];
        ll j = p;
        if(j < a)    j = ((a+p-1)/p)*p;    //j = ceil(a/p)*p
        for(; j <= b; j+=p){    //j is the smallest multiple of p
            phi[j-a] /= p;
            phi[j-a] *= (p-1);
            while(r[j-a]%p == 0){
                r[j-a]/=p;
            }
        }
    }
    for(ll i = a; i<= b; i++){
        if(r[i-a] > 1){
            phi[i-a] /= r[i-a];
            phi[i-a] *= (r[i-a]-1);
        }
    }
    for(ll i = a;i <= b; i++){
        if(i != b)
            printf("%lld\n",phi[i-a]);
        else
            printf("%lld",phi[i-a]);
    }
    return;
}

int main(){
    io;
    sieve();
    ll a, b;
    cin>>a>>b;
    segmentedSieve(a,b);
    return 0;
}
