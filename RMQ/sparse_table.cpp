#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);

const int N = 1e5 + 5;
const int LOG = log2(N) + 1;
int ST[LOG][N];
int A[N];
int n;

// <O(NlogN), O(1)>
// query O(1) only for idempotent functions, otherwise O(log(n))

// ST[i][j] index of minimum value in subarray starting at index i having len 2^j
// ST[i][j] = min( A[i], A[i + 1], ...., A[i + 2^j - 1] )

void pre(){
    // storing index of the minimum element
    for(int i = 0; i < n; i++)
        ST[0][i] = i;
    for(int j = 1; j < LOG; j++){
        for(int i = 0; i + (1 << j) - 1 < n; i++){
            if(A[ ST[j - 1][i] ] < A[ ST[j - 1][ i + (1 << (j - 1)) ] ])
                ST[j][i] = ST[j - 1][i];
            else
                ST[j][i] = ST[j - 1][ i + (1 << (j - 1)) ];
        }
    }
}

int query(int left, int right){
    int range = right - left + 1;
    int k = log2(range);
    return min(A[ ST[k][left] ], A[ ST[k][ right - (1 << k) + 1 ] ]);
}

int main(){
    io;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> A[i];
    pre();
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << endl;
    }
    return 0;
}