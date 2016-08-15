/*
	Time complexity - 
						find(a, b)	O(1)
						union(a, b)	O(n)

*/

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[100005];
void initialize(){
	for(int i = 1;i <= n; i++){
		arr[i] = i;
	}
}

void union1(int a, int b){
	int temp = arr[a];
	for(int i = 1;i <= n; i++){
		if(arr[i] == temp){
			arr[i] = arr[b];
		}
	}
}

bool find(int a, int b){
	return arr[a] == arr[b];
}
int main(){
	n = 5;
	initialize();
	union1(1, 2);
	union1(2, 4);
	cout<<find(2, 5)<<endl;
	cout<<find(1, 4)<<endl;
	return 0;
}