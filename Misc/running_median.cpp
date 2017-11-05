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

const int MAXN = 1e5+5;

int main(){
	io;
	// if even numbers then lower one is median
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0;i < n; i++)
		cin >> arr[i];
	priority_queue<int, vector<int>, less<int> > lowers;	// max pq
	priority_queue<int, vector<int>, greater<int> > uppers;	// min pq
	lowers.push(arr[0]);
	for(int i = 1; i < n; i++){
		int median = lowers.top();
		cout << median << endl;
		int curr = arr[i];
		// rebalancing
		if(uppers.size() < lowers.size()){
			if(curr < lowers.top()){
				// difference more than 1
				lowers.push(curr);
				uppers.push(lowers.top());
				lowers.pop();
			}else
				uppers.push(curr);
		}else{
			// 	uppers size greater or equal
			if(curr > uppers.top()){
				uppers.push(curr);
				lowers.push(uppers.top());
				uppers.pop();
			}else
				lowers.push(curr);
		}
	}
	cout << lowers.top() << endl;
	return 0;
}