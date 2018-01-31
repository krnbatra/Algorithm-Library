#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAXN = 1e5+5;

int P[MAXN*2];

string convert(const string &s){
    string newString = "@";
    for(int i = 0;i < s.size(); i++){
        newString += "#" + s.substr(i, 1);
    }
    newString += "#$";
    return newString;
}

int lps(const string &s){
    string str = convert(s);
    int c = 0, r = 0;   // c - center of main palindrome, r - right boundary of main palindrome
    for(int i = 1;i < str.size()-1; i++){
        int mirr = 2*c - i;     // mirror of i in the main palindrome
        if(i < r)
            P[i] = min(r-i, P[mirr]);
        while(str[i+1+P[i]] == str[i-1-P[i]])   // try expanding around i
            P[i]++;
        if(i+P[i] > r){     // update the main palindrome
            c = i;
            r = i + P[i];
        }
    }
    return *max_element(P, P+str.size()-1);
}

int main(){
    io;
    string s;
    cin >> s;
    cout << lps(s) << endl;
    return 0;
}