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

const int N = 1e3 + 5;
int BIT[2][N];
 
void update(int bit, int idx, int val){
    while(idx < N){
        BIT[bit][idx] += val;
        idx += idx & -idx;
    }
    return;
}
 
void range_update(int l, int r, int val){
    update(0, l, val);
    update(0, r + 1, -val);
    update(1, l, val * (l - 1));
    update(1, r + 1, -val * r);
    return;
}
 
int query(int bit, int idx){
    int sum = 0;
    while(idx > 0){
        sum += BIT[bit][idx];
        idx -= idx & -idx;
    }
    return sum;
}
 
int range_query(int idx){
    return idx * query(0, idx) - query(1, idx);
}
 
int range_query(int l, int r){
    return range_query(r) - range_query(l - 1);
}

int main(){
    io;
    range_update(2, 4, 2);
    cout << range_query(2, 3) << endl;
    return 0;
}