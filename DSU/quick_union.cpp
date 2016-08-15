/*
	Time complexity - 
						find(a, b)	O(n)
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

int root(int i){
	while(i!=arr[i]){
		i = arr[i];
	}
	return i;
}

void union1(int a, int b){
	int root_a = root(a);
	int root_b = root(b);
	arr[root_a] = root_b;
}

bool find(int a, int b){
	return root(a)==root(b);
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