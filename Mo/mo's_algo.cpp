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

const int N = 2e5+1;
const int M = 1e6+5;
const int SQN = sqrt(N)+1;

int n, q;
int arr[N];
ll print[N];
int cnt[M];

struct query{
	int l, r;
	int idx;
	int block;
	query(){}
	query(int _l, int _r, int _id){
		l = _l;
		r = _r;
		idx = _id;
		block = _l/SQN;
	}
	bool operator < (const query &b) const{
		if(block != b.block){
			return block < b.block;
		}
		return r < b.r;
	}
};

query Q[N];
int main(){
	io;
	cin >> n >> q;
	for(int i = 1;i <= n; i++)
		cin >> arr[i];
	for(int i = 1;i <= q; i++){
		int l, r;
		cin >> l >> r;
		Q[i] = query(l, r, i);
	}
	sort(Q+1, Q+1+q);
	ll ans = 0;
	int currL = 1, currR = 0;
	for(int i = 1;i <= q; i++){
		int l = Q[i].l;
		int r = Q[i].r;
		int id = Q[i].idx;
		while(currR < r){
			++currR;
			ans += 1LL * arr[currR] * (cnt[arr[currR]] + cnt[arr[currR]] + 1LL);
			++cnt[arr[currR]];
		}
		while(currL > l){
			--currL;
			ans += 1LL * arr[currL] * (cnt[arr[currL]] + cnt[arr[currL]] + 1LL);
			++cnt[arr[currL]];
		}
		while(currR > r){
			ans -= 1LL * arr[currR] * (cnt[arr[currR]] + cnt[arr[currR]] - 1LL);
			--cnt[arr[currR]];
			--currR;
		}
		while(currL < l){
			ans -= 1LL * arr[currL] * (cnt[arr[currL]] + cnt[arr[currL]] - 1LL);
			--cnt[arr[currL]];
			++currL;
		}
		print[id] = ans;
	}
	for(int i = 1;i <= q; i++)
		cout << print[i] << endl;
	return 0;
}