/*My First Template :D*/
#include <bits/stdc++.h>
#include <limits.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
 
#define MOD (ll)1000000007
#define pb   push_back
#define EPS 1e-9
#define FOR(i,n)  for(int i = 0;i < n; i++)
#define FORE(i,a,b) for(int i = a;i <= b; i++)
#define pi(a)   printf("%d\n", a)
#define all(c)  c.begin(), c.end()
#define tr(container, it)   for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define gc getchar_unlocked
#define sdi(a, b)   si(a);si(b)
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
#define F first
#define S second
#define FILL(arr, val)  memset(arr, val, sizeof(arr))
#define read(arr, n)    for(int i = 0;i < n; i++)cin>>arr[i];
#define sp ' '

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}

void si(int &x){
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

const int MAXN = (int)1e3+5;
int size;
int BIT1[MAXN], BIT2[MAXN], arr[MAXN];

void update(int idx, int val, int tree){
    while(idx <= MAXN){
        if(tree == 1)
            BIT1[idx] += val;
        if(tree == 2)
            BIT2[idx] += val;
        // move up in the table
        idx += idx&(-idx);
    }
}

void updateRange(int i, int j, int val){
    update(i, val, 1);
    update(j+1, -val, 1);
    update(i, val*(i-1), 2);
    update(j+1, -val*j, 2);
}

int queryTree(int idx, int tree){
    int sum = 0;
    while(idx > 0){
        if(tree == 1)
            sum += BIT1[idx];
        if(tree == 2)
            sum += BIT2[idx];
        idx -= idx&(-idx);
    }
    return sum;
}

// return sum[1....idx]
int query(int idx){
    return idx*queryTree(idx, 1) - queryTree(idx, 2);
}

int queryRange(int i, int j){
    return query(j) - query(i-1);
}

int main(){
    io;
    cin >> size;
    for(int i = 1;i <= size; i++){
        cin >> arr[i];
        update(i, arr[i]);
    }
    return 0;
}
