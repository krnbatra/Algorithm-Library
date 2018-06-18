#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);

const int N = 3e5 + 5;
const int LOG = 31;

struct node{
	int present;
	node* link[2];
	
	node(){
		link[0] = link[1] = NULL;
		present = 0;
	}

	void insert(int val){
		node* current = this;
		for(int i = LOG; i >= 0; i--){
			int bit = (val & (1LL << i)) > 0;
			if(current->link[bit] == NULL)
				current->link[bit] = new node();
			// bacche ko increase
			current->link[bit]->present += 1;
			current = current->link[bit];
		}
		return;
	}

	int query(int val){
		node* current = this;
		int ans = 0;
		// number min xor with val
		for(int i = LOG; i >= 0; i--){
			int bit = (val & (1LL << i)) > 0;
			if(current->link[bit] != NULL && current->link[bit]->present){
				if(bit)	ans += (1 << i);
				current->link[bit]->present -= 1;
				current = current->link[bit];
			}else{
				bit ^= 1;
				if(current->link[bit] != NULL && current->link[bit]->present){
					if(bit)	ans += (1 << i);
					current->link[bit]->present -= 1;
					current = current->link[bit];
				}
			}
		}
		return ans;
	}
};

node* root;

int main(){
    io;
	// root->insert()
	// root->query()
    return 0;
}