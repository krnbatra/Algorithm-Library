/*Let's get high :D*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define M_PI                3.14159265358979323846

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}

const int MAXN = 500005;
int sz = 0;

int trie[26][MAXN];
int end1[MAXN];

void insert(string s){
    int v = 0;
    for(int i = 0; i < s.size(); i++){
        int c = s[i]-'a';
        if(trie[c][v] == -1)
            trie[c][v] = ++sz;
        v = trie[c][v];
    }
    ++end1[v];
}

bool searchPrefix(string prefix){
    int v = 0;
    int i;
    for(i = 0; i < prefix.size(); i++){
        int c = prefix[i]-'a';
        if(trie[c][v] == -1)
            return false;
        v = trie[c][v];
    }
    return i == prefix.size();
}


bool searchWord(string prefix){
    int v = 0;
    int i;
    for(i = 0; i < prefix.size(); i++){
        int c = prefix[i]-'a';
        if(trie[c][v] == -1)
            return false;
        v = trie[c][v];
    }
    return end1[v] > 0;
}

int main(){
    io;
    memset(trie, -1, sizeof trie);
    insert("abc");
    cout << end1[3] << endl;
    return 0;
}
