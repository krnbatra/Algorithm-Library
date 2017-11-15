#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAXN = 1025;
int BIT[MAXN][MAXN];
int arr[MAXN][MAXN];
int n;

void update(int x, int y, int val){
  while(x <= MAXN){
    int y1 = y;
    while(y1 <= MAXN){
      BIT[x][y1] += val;
      y1 += y1&-y1;
    }
    x += x&-x;
  }
}

int query(int x, int y){
  int sum = 0;
  while(x > 0){
    int y1 = y;
    while(y1 > 0){
      sum += BIT[x][y1];
      y1 -= y1&-y1;
    }
    x -= x&-x;
  }
  return sum;
}

int RSQ(int x1, int y1, int x2, int y2){
  return query(x2, y2) - query(x2, y1-1) - query(x1-1, y2) + query(x1-1, y1-1);
}

int main(){
    io;
    
    return 0;
}