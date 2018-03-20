#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl				'\n'
#define trace1(x)			cerr<<#x<<": "<<x<<endl
#define trace2(x, y)		cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)		cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)	cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl

const int N = 1e5 + 5;
const int p = 31;
ll p_pow[N];


void cal_pow(){
    p_pow[0] = 1LL;
    for(int i = 1; i < N; i++)
        p_pow[i] = (p_pow[i - 1] * p) % MOD;
}

int get_unique_substrings(string &s){
    cal_pow();
    int n = s.size();
    vector<ll> h(n + 1, 0);
    for(int i = 0; i < n; i++)
        h[i + 1] = (h[i] + ((s[i] - 'a' + 1) * p_pow[i]) % MOD) % MOD;
    int cnt = 0;
    for(int l = 1; l <= n; l++){
        unordered_set<ll> hs;
        for(int i = 0; i <= n - l; i++){
            ll curr_h = (h[i + l] - h[i] + MOD) % MOD;
            curr_h = (curr_h * p_pow[n - i - 1]) % MOD;
            hs.insert(curr_h);
        }
        cnt += hs.size();
    }
    return cnt;
}

int main(){
	io;
	string s = "ababa";
	cout << get_unique_substrings(s) << endl;
    return 0;
}