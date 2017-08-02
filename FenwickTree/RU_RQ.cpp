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

const int MAXN = 1e3+5;
int BIT1[MAXN], BIT2[MAXN];

void update(int idx, int val, int bit){
    while(idx <= MAXN){
        if(bit == 1)
            BIT1[idx] += val;
        else
            BIT2[idx] += val;
        idx += idx&-idx;
    }
}

void udpateRange(int l, int r, int val){
    update(l, val, 1);
    update(r+1, -val, 1);
    update(l, val*(l-1), 2);
    update(r+1, -val*r, 2);
}

int queryTree(int idx, int bit){
    int sum = 0;
    while(idx > 0){
        sum += (bit)?BIT1[idx]:BIT2[idx];
        idx -= idx&-idx;
    }
    return sum;
}

int query(int idx){
    return idx*queryTree(idx, 1) - queryTree(idx, 2);
}

int queryRange(int l, int r){
    return query(r)-query(l-1);
}

int main(){
    io;
    udpateRange(2, 4, 2);
    cout << queryRange(2, 3) << endl;
    return 0;
}