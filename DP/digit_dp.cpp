#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define M_PI                3.14159265358979323846

const int MAXN = 5e2+5;

string a, b;
int n;
int dp[12][100][2];

bool isPrime[MAXN];

void sieve(){
    memset(isPrime, true, sizeof isPrime);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2;i <= 1000; i++){
        if(isPrime[i]){
            for(int j = i*i;j <= 1000; j+=i)
                isPrime[j] = false;
        }
    }
}

ll solve(string &s, int idx, ll sum, int isPrefixEqual){
    if(dp[idx][sum][isPrefixEqual] != -1)
        return dp[idx][sum][isPrefixEqual];
    ll res = 0;
    if(idx == n){
        if(isPrime[sum])
            res = 1;
    }else{
        if(isPrefixEqual){
            for(int i = 0;i <= s[idx]-'0'; i++){
                if(i == s[idx]-'0'){
                    res += solve(s, idx+1, sum + i, 1);
                }else{
                    res += solve(s, idx+1, sum + i, 0);
                }
            }
        }else{
            for(int i = 0;i < 10; i++){
                res += solve(s, idx+1, sum + i, 0);
            }
        }
    }
    dp[idx][sum][isPrefixEqual] = res;
    return res;
}

int f(string &a){
    bool odd = true;
    ll sum = 0;
    for(int i = (int)a.size()-1;i >= 0; i--){
        sum += a[i] - '0';
    }
    return (isPrime[sum]);
}

int main(){
    io;
    sieve();
    int t;
    cin >> t;
    while(t--){
        cin >> a >> b;
        memset(dp, -1, sizeof dp);
        n = b.size();
        ll ansR = solve(b, 0, 0, 1);
        memset(dp, -1, sizeof dp);
        n = a.size();
        ll ansL = solve(a, 0, 0, 1);
        ll ans = ansR - ansL + f(a);
        cout << ans << endl;
    }
    return 0;
}