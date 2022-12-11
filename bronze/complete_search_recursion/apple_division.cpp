#include<bits/stdc++.h>
#define ll long long
using namespace std;

void recur(vector<int> &arr, int i, ll tot, ll &ans, ll T){
  if (i >= arr.size()){
    ans = min(ans,abs(T-tot - tot));
    return;
  }
  recur(arr, i+1, tot + arr[i], ans, T);
  recur(arr, i+1, tot, ans, T);
}

int main(){
  ll n, tot = 0;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; ++i)
    cin >> arr[i], tot += arr[i];

  ll ans = tot;
  recur(arr, 0, 0, ans, tot);
  cout << ans << "\n";
  return 0;
}