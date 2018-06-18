#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);

const int N = 1e3 + 5;
int BIT[2][N];
 
void update(int bit, int idx, int val){
    while(idx <= 500000){
        BIT[bit][idx] += val;
        idx += idx&-idx;
    }
}
 
void udpateRange(int l, int r, int val){
    update(0, l, val);
    update(0, r+1, -val);
    update(1, l, val*(l-1));
    update(1, r+1, -val*r);
}
 
int queryTree(int bit, int idx){
    int sum = 0;
    while(idx > 0){
        sum += BIT[bit][idx];
        idx -= idx&-idx;
    }
    return sum;
}
 
int query(int idx){
    return idx*queryTree(0, idx) - queryTree(1, idx);
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