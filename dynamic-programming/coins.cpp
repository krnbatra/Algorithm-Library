#include <bits/stdc++.h>
#include <limits.h>
using namespace std;
int main(){
  int coins[3] = {1, 3, 5};
  int minn[12];
  minn[0] = 0;
  for(int i = 1;i <= 11; i++){
    minn[i] = INT_MAX;
  }
  for(int i = 1;i <= 11; i++){
    int sum = i;
    int j = 0;
    while(j < 3 && coins[j] <= sum){
      minn[i] = min(minn[i], minn[sum-coins[j]]+1);
      j++;
    }
  }
  for(int i = 0;i <= 11; i++){
    cout<<minn[i]<<endl;
  }
  return 0;
}
