#include<iostream>
#define ll long long
using namespace std;

int main(){
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    ll x, y, m;
    cin >> x >> y >> m;
    int xb = m / x, yb = m / y;
    ll ans = INT_MIN;

    for (int i = 0; i <= xb; ++i){
        for (int k = 0; k <= yb; ++k){
            ll res = x*i + y*k;
            if (res > m) continue;
            ans = max(ans,res);
        }
    }

    for (int k = 0; k <= yb; ++k){
        for (int i = 0; i <= xb; ++i){
            ll res = x*i + y*k;
            if (res > m) continue;
            ans = max(ans, x*i + y*k);
        }
    }
    cout << ans << "\n";
    return 0;
}