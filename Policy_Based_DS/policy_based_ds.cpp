#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
 
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

ordered_set<int> X;

/* 
	find_by_order() - Returns an iterator to the k-th largest element (counting from zero)
	order_of_key()  - Number of items in a set that are strictly smaller than our item.
*/

int main(){
	X.insert(1);
    X.insert(2);
    X.insert(4);
    X.insert(8);
    X.insert(16);
    cout << *X.find_by_order(1) << endl;
    cout << X.order_of_key(5) << endl;
	return 0;
}