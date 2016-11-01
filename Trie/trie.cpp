#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define pb push_back

const int MAXN = 26;

struct Trie{
	int words;
	int prefixes;
	Trie* edges[MAXN];
	Trie(){
		words = 0;
		prefixes = 0;
		for(int i = 0 ;i < MAXN; i++)
			edges[i] = NULL;
	}
};

Trie root;
int size;
string word;

void addWord(Trie* vertex, int idx){
	if(idx == word.size()){
		vertex->words++;
		return;
	}
	vertex->prefixes++;
	if(vertex->edges[word[idx]-'a'] == NULL){
		vertex->edges[word[idx]-'a'] = new Trie;
	}
	addWord(vertex->edges[word[idx]-'a'], idx+1);
}

int countWords(Trie* vertex, int idx){
	if(idx == word.size())
		return vertex->words;
	else if(vertex->edges[word[idx]-'a'] == NULL)
		return 0;
	return countWords(vertex->edges[word[idx]-'a'], idx+1);
}

int countPrefixes(Trie* vertex, int idx){
	if(idx == prefix.size())
		return vertex->prefixes;
	else if(vertex->edges[prefix[idx]-'a'] == NULL)
		return 0;
	return countPrefixes(vertex->edges[prefix[idx]-'a'], idx+1);
}


int main(){
	cout << root.words << endl;
	return 0;
}