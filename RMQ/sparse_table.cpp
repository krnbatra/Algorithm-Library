/*Let's get high :D*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define M_PI                3.14159265358979323846

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}

const int MAXN = 1e5+5;
const int LG = log2(MAXN) + 1;
int sparse_table[LG][MAXN];
int A[MAXN];
int n;

// <O(NlogN), O(1)>
// query O(1) only for idempotent functions, otherwise O(log(n))

void preprocess(){
    // storing index of the minimum element
    for(int i = 0; i < n; i++)
        sparse_table[0][i] = i;
    for(int j = 1; j < LG; j++){
        for(int i = 0; i + (1 << j) - 1 < n; i++){
            if(A[sparse_table[j-1][i]] < A[sparse_table[j-1][i + (1 << (j-1))]])
                sparse_table[j][i] = sparse_table[j-1][i];
            else
                sparse_table[j][i] = sparse_table[j-1][i + (1 << (j-1))];
        }
    }
}

int query(int left, int right){
    int range = right - left + 1;
    int k = log2(range);
    return min(A[sparse_table[k][left]], A[sparse_table[k][right - (1 << k) + 1]]);
}

int main(){
    io;
    cin >> n;
    for(int i = 0;i < n; i++)
        cin >> A[i];
    preprocess();
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << endl;
    }
    return 0;
}