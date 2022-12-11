// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int check(set<string> &a, set<string> &b){
	int cnt = 0;
	for(string str: a){
		if (b.count(str)) ++cnt;
	}
	return cnt;
}


int main() {
	freopen("guess.in", "r", stdin);
	freopen("guess.out", "w", stdout);

	int N; cin >> N;
	set<string> animalCharacteristics[N];

	for (int i = 0; i < N; ++i){
		string animal; cin >> animal;
		int cnt; cin >> cnt;

		for (int c = 0; c < cnt; ++c){
			string tmp; cin >> tmp;
			animalCharacteristics[i].insert(tmp);
		}
	}

	int ans = 0;
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j){
			if (i == j) continue; // so that we are not checking our own self
			ans = max(ans, check(animalCharacteristics[i], animalCharacteristics[j]));
		}
	}
	cout << ans+1 << "\n";
	return 0;
}
