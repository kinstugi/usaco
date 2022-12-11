// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool isConflicted(pair<int, char> a, pair<int, char> b){
	ll lb = 0, hb = 1e9;
	if (a.second == 'G') lb = a.first;
	else hb = a.first;

	if (b.second == 'G') return lb >= b.first;
	else return hb <= b.first;
	return true;
}

int main(){
	int n; cin >> n;
	int ans = INT_MAX;
	vector<pair<ll, char> > arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i].second >> arr[i].first;
	sort(arr.begin(), arr.end());

	vector<int> left_lying(n, 0);
	vector<int> right_lying(n, 0);

	for (int i = 1; i < n; ++i){
		left_lying[i] = left_lying[i-1];
		if (arr[i - 1].second == 'L' && arr[i].first > arr[i - 1].first)
			left_lying[i]++;
	}

	for (int i = n - 2; i > -1; --i){
		right_lying[i] = right_lying[i+1];
		if (arr[i + 1].second == 'G' && arr[i].first < arr[i + 1].first)
			right_lying[i]++;
	}

	for (int i = 0; i < n; ++i)
		ans = min(ans, right_lying[i] + left_lying[i]);
	cout << ans << "\n";
	return 0;
}