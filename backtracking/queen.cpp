#include <bits/stdc++.h>
using namespace std;
const int n = 8;
bool has_queen[n][n];
int queens_left = n;
void generate(int x, int y){
  if(y == n){
    generate(x+1, 0);
  }else if(x == n){
    if(queens_left==0){
      for(int i = 0;i < n; i++){
        for(int j = 0; j < n; j++){
          if(has_queen[i][j]){
            cout<<"Q";
          }else
            cout<<".";
        }
        cout<<endl;
      }
    }
  }else{

  }
}
int main(){
  memset(has_queen, 0, sizeof(has_queen));
  generate(0, 0);
  return 0;
}

