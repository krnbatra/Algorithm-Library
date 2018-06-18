#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);

const int N = 500005;
int sz = 0;

int trie[26][N];
int end1[N];

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