#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define pb push_back

const int MAXN = (int)1e6+5;
ll phi[MAXN+1];
void precal(){
	for(int i = 1;i <= MAXN; i++){
		phi[i] = i;
	}
	for(int i = 2; i <= MAXN; i++){
		if(phi[i] == i){
			for(int j = i; j <= MAXN; j+=i){
				phi[j] /= i;
				phi[j] *= (i-1);
			}
		}
	}
}

int main(){
	precal();
	cout<<phi[8]<<endl;
	return 0;
}