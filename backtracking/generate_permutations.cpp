#include <bits/stdc++.h>
using namespace std;
const int n = 5;
int perm[n];
int used[n];

void generate(int at){
  if(at==n){
    for(int i = 0;i < n; i++){
      printf("%d ", perm[i]);
    }
    cout<<endl;
  }else{
    //decide what the at-th element should be
    for(int i = 0;i < n; i++){
      if(!used[i]){
        used[i] = 1;
        perm[at] = i;
        generate(at+1);
        //remember to undo the move
        used[i] = 0;
      }
    }
  }
}
int main(){
  memset(used, 0, n);
  generate(0);
  return 0;
}