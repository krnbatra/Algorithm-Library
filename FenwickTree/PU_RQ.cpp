#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);

const int N = 1e3 + 5;
int BIT[N], arr[N];

void update(int idx, int val){
    while(idx < N){
        BIT[idx] += val;
        idx += idx & -idx;
    }
    return;
}

int query(int idx){
    int sum = 0;
    while(idx > 0){
        sum += BIT[idx];
        idx -= idx & -idx;
    }
    return sum;
}

int main(){
    io;
    
    return 0;
}