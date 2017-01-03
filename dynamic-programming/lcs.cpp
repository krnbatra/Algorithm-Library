#include <bits/stdc++.h>
#include <limits.h>
using namespace std;
int lcs(string input1,string input2){
  if(input1.size() == 0 || input2.size() == 0)
    return 0;
  if(input1[0] == input2[0])
    return 1+lcs(input1.substr(1, input1.size()-1), input2.substr(1, input2.size()-1));
  return max(lcs(input1.substr(1, input1.size()-1), input2), lcs(input1, input2.substr(1, input2.size()-1)));
}
int lcs_dp(string input1, string input2){
  int table[input1.size()+1][input2.size()+1]; //table[i][j] contains lcs of input1[0...i-1], input2[0.....j-1]
  for(int i = 0;i <= input1.size(); i++){
    for(int j = 0;j <= input2.size(); j++){
      if(i == 0 || j == 0)
          table[i][j] = 0;
      if(input1[i-1] == input2[j-1])
        table[i][j] = 1+table[i-1][j-1]; 
      else
        table[i][j] = max(table[i-1][j], table[i][j-1]);
    }
  }
  return table[input1.size()][input2.size()];
}
int main(){
  string input1 = "KARAN";
  string input2 = "BATRA";
  cout<<lcs_dp(input1, input2)<<endl;
  return 0;
}
