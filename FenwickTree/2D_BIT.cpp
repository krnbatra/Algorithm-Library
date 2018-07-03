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

const int N = 1e3 + 5;
int BIT[N][N];
int arr[N][N];
int n;

void update(int x, int y, int val){
	while(x < N){
		int y1 = y;
		while(y1 < N){
		  BIT[x][y1] += val;
		  y1 += y1 & -y1;
		}
		x += x & -x;
	}
}

int query(int x, int y){
	int sum = 0;
	while(x > 0){
		int y1 = y;
		while(y1 > 0){
			sum += BIT[x][y1];
			y1 -= y1 & -y1;
		}
		x -= x & -x;
	}
	return sum;
}

int RSQ(int x1, int y1, int x2, int y2){
	return query(x2, y2) - query(x2, y1-1) - query(x1-1, y2) + query(x1-1, y1-1);
}

int main(){
	io;
	
	return 0;
}