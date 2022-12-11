// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	int ans = 0;
	for(int i = 0; i < n; ++i){
		ll tot = 0;
		for (int j = i; j < n; ++j){
			tot += arr[j];
			
			for (int k = i; k <= j; ++k){
				if (arr[k] * (j-i+1) == tot){ ++ans; break;}
			}
		}
	}
	cout << ans;
}
