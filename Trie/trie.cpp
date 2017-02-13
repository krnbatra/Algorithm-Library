/*My First Template :D*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
 
#define MOD (ll)1000000007
#define pb   push_back
#define EPS 1e-9
#define FOR(i,n)  for(int i = 0;i < n; i++)
#define FORE(i,a,b) for(int i = a;i <= b; i++)
#define tr(container, it)   for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
#define F first
#define S second
#define sp ' '

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}

const int MAXN = 26;

struct Trie{
    int words;
    int prefixes;
    Trie* edges[MAXN];
    Trie(){
        words = 0;
        prefixes = 0;
        for(int i = 0;i < MAXN; i++){
            edges[i] = NULL;
        }
    }
};

Trie root;
string input;

void addWord(Trie* vertex, int idx){
    if(idx == input.size()){
        vertex->prefixes++;
        vertex->words++; return;
    }
    vertex->prefixes++;
    if(vertex->edges[input[idx]-'a'] == NULL)
        vertex->edges[input[idx]-'a'] = new Trie;
    addWord(vertex->edges[input[idx]-'a'], idx+1);
}

int countWords(Trie* vertex, int idx){
    if(idx == input.size())
        return vertex->words;
    if(vertex->edges[input[idx]-'a'] == NULL)
        return 0;
    return countWords(vertex->edges[input[idx]-'a'], idx+1);
}

int countPrefixes(Trie* vertex, int idx){
    if(idx == input.size())
        return vertex->prefixes;
    if(vertex->edges[input[idx]-'a'] == NULL)
        return 0;
    return countPrefixes(vertex->edges[input[idx]-'a'], idx+1);
}

void init(){
    root.words = 0;
    root.prefixes = 0;
    FOR(i, MAXN)    root.edges[i] = NULL;
}

int main(){
    io;
    init();
    input = "karan";
    addWord(&root, 0);
    cout << countWords(&root, 0) << endl;
    return 0;
}
