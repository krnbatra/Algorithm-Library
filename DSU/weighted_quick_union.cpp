/*
	Time complexity - 
						find(a, b)	O(logn)
						union(a, b)	O(logn)

*/
#include <bits/stdc++.h>
using namespace std;
int n;
int parent[100005];
int size[100005];
void initialize(){
	for(int i = 1;i <= n; i++){
		parent[i] = i;
		size[i] = 1;
	}
}
int root(int i){
	while(i!=parent[i]){
		i = parent[i];
	}
	return i;
}
bool find(int a, int b){
	return root(a) == root(b);
}
void union1(int a, int b){
	int root_a = root(a);
	int root_b = root(b);
	
	if(root_a == root_b)
		return;
	
	if(size[root_a] < size[root_b]){
		parent[root_a] = root_b;
		size[root_b]+=size[root_a];
	}else{
		parent[root_b] = root_a;
		size[root_a]+=size[root_b];
	}
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