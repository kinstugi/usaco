// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main() {
	freopen("diamond.in","r",stdin);
	freopen("diamond.out","w",stdout);
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	sort(arr.begin(), arr.end());
	int ans = 0;
	for (int i = 0; i < n; ++i){
		int cnt = 1;
		for (int j = i+1; j < n; ++j){
			if (arr[j]-arr[i] <= k) cnt++;
			else break;
		}
		ans = max(ans, cnt);
	}
	cout << ans << "\n";
	return 0;
}
