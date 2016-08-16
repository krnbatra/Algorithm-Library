/*
	Time complexity - 
						find(a, b)	O(1)
						union(a, b)	O(n)

*/

#include <bits/stdc++.h>
using namespace std;
int n;
int parent[100005];
void initialize(){
	for(int i = 1;i <= n; i++){
		parent[i] = i;
	}
}

void union1(int a, int b){
	int temp = parent[a];
	for(int i = 1;i <= n; i++){
		if(parent[i] == temp){
			parent[i] = parent[b];
		}
	}
}

bool find(int a, int b){
	return parent[a] == parent[b];
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