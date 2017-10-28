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

struct node{
	int leftc;
	int rightc;
	node* left;
	node* right;
	node(){
		leftc = 0;
		rightc = 0;
		left = NULL;
		right = NULL;
	}
};

node root;

void init(){
	root.leftc = 0;
	root.rightc = 0;
	root.left = NULL;
	root.right = NULL;
}

void insert(node* curr, int n, int level){
	if(level == -1)
		return;
	int x = ((n >> level) & 1);
	if(x){
		curr->rightc++;
		if(curr->right == NULL)
			curr->right = new node;
		insert(curr->right, n, level-1);
	}else{
		curr->leftc++;
		if(curr->left == NULL)
			curr->left = new node;
		insert(curr->left, n, level-1);
	}
}

void query(node* curr, int n, int level, int &ans){
	if(level == -1 || curr == NULL)
		return;
	// number max xor with n
	int x = ((n >> level) & 1);
	if(x){
		if(curr->left != NULL){
			ans += (1 << level);
			query(curr->left, n, level-1, ans);
		}else{
			query(curr->right, n, level-1, ans);
		}
	}else{
		if(curr->right != NULL){
			ans += (1 << level);
			query(curr->right, n, level-1, ans);
		}else{
			query(curr->left, n, level-1, ans);
		}
	}
}

int main(){
    io;
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	int ans = INT_MIN;
	init();
	for(int i = 0; i < n; i++){
		int val = 0;
		query(&root, arr[i], 31, val);
		ans = max(ans, val);
		insert(&root, arr[i], 31);
	}
	cout << ans << endl;
    return 0;
}