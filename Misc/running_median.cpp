#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);

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