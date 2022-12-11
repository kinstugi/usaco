#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 105;

int main() {
	freopen("triangles.in", "r", stdin);
	freopen("triangles.out", "w", stdout);
	int n; cin >> n;
	int x[MAX_N];
	int y[MAX_N];
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				// Check to see if both points are parallel to the X and Y axis
				if (y[i] == y[j] && x[i] == x[k]) {
					int area = abs((x[j] - x[i]) * (y[k] - y[i]));
					ans = max(ans, area);
				}
			}
		}
	}
	cout << ans << endl;
}