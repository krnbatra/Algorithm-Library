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

const int N = 5e5 + 5;

vector<int> adj[N], adjR[N];
int components[N];
int n, m, c;
bool vis[N];
stack<int> stk;
vector<int> comp[N];
vector<int> top_sort;

void add_or(int u, int v, int rev){
	u *= 2, v *= 2;
	if(rev == 0){
		adj[u ^ 1].push_back(v);
		adj[v ^ 1].push_back(u);
	}else{
		adjR[v].push_back(u ^ 1);
		adjR[u].push_back(v ^ 1);
	}
}

void add_xor(int u, int v, int rev){
	u *= 2, v *= 2;
	if(rev == 0){
		adj[u ^ 1].push_back(v);
		adj[v ^ 1].push_back(u);
		adj[u].push_back(v ^ 1);
		adj[v].push_back(u ^ 1);
	}else{
		adjR[v].push_back(u ^ 1);
		adjR[u].push_back(v ^ 1);
		adjR[v ^ 1].push_back(u);
		adjR[u ^ 1].push_back(v);
	}
}

void init(){
    c = 0;
    for(int i = 0; i <= 2 * n + 1; i++){
        vis[i] = false;
        adj[i].clear();
        adjR[i].clear();
        comp[i].clear();
    }
}

void dfs0(int u){
    vis[u] = 1;
    for(auto v : adj[u]){
        if(!vis[v])
            dfs0(v);
    }
    stk.push(u);
}

void dfs1(int u){
    vis[u] = 1;
    components[u] = c;
    comp[c].push_back(u);
    for(auto v : adjR[u]){
        if(!vis[v])
            dfs1(v);
    }
}

void scc(){
    memset(vis, false, sizeof vis);
    while(!stk.empty()){
        int ele = stk.top();
        stk.pop();
        if(!vis[ele]){
            c++;
            dfs1(ele);
        }
    }
}

int main(){
	io;
	int t;
	cin >> t;
	while(t--){
		cin >> n >> m;
		init();
		for(int i = 0; i < m; i++){
			int a, b;
			cin >> a >> b;
			add_or(a, b, 0);
			add_or(a, b, 1);
		}
		for(int i = 1; i <= n / 2; i++){
			int a = 2 * i, b = 2 * i - 1;
			add_xor(a, b, 0);
			add_xor(a, b, 1);
		}
		for(int i = 2; i <= 2 * n + 1; i++){
			if(!vis[i])
				dfs0(i);
		}
		scc();
		int flag = 0;
		for(int i = 2; i <= 2 * n + 1; i++){
			if(components[i] == components[i ^ 1]){
				cout << "impossible" << "\n";
				flag = 1;
				break;
			}
		}
		if(flag)	continue;
		memset(vis, false, sizeof vis);
		cout << "possible" << "\n";
		unordered_set<int> belongs_a;
		for(int i = c; i >= 0; i--){
			if(comp[i].size() == 0)	continue;
			for(auto j : comp[i]){
				if(vis[j / 2])	continue;
				vis[j / 2] = 1;
				if(j % 2 == 0)
					belongs_a.insert(j / 2);
			}
		}
		string s;
		for(int i = 1; i <= n; i++){
			if(belongs_a.find(i) == belongs_a.end()){
				s += "0";
			}else
				s += "1";
		}
		cout << s << "\n";
	}
	return 0;
}