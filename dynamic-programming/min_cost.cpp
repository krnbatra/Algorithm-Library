#include <iostream>
#include <limits.h>
#define R 3
#define C 3
using namespace std;
int minCost(int cost[][C], int n, int m){
  if(n < 0 || m < 0)
    return INT_MAX;
  if(n==0 && m==0)
    return cost[0][0];
  return min(minCost(cost, n-1, m-1), min(minCost(cost, m-1, n), minCost(cost, m, n-1)))+cost[m][n];
}
int memo[10][10];
int minCostTopDown(int cost[][C], int n, int m){
  if(memo[n][m]!=INT_MAX)
    return memo[n][m];
  if(n < 0 || m < 0)
    return INT_MAX;
  if(n==0 || m==0)
    return memo[n][m] = cost[n][m];
  return memo[n][m] = min(minCost(cost, n-1, m-1), min(minCost(cost, m-1, n), minCost(cost, m, n-1)))+cost[m][n];
}
int main(){
  int cost[R][C] = { {1, 2, 3}, {4, 8, 2}, {1, 5, 3}};
  for(int i = 0;i < 10; i++){
    for(int j = 0;j < 10; j++){
      memo[i][j] = INT_MAX;
    }
  }
  cout<<minCostTopDown(cost, 2, 2)<<endl;
  return 0;
}
