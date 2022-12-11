#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long

using namespace std;

int main(){
    //freopen("input.in", "r", stdin);
    int n; cin >> n;
    vector<ll> xcoordinates(n);
    vector<ll> ycoordinates(n);

    for (int i=0; i < n; ++i)
        cin >> xcoordinates[i];
    for (int i=0; i < n; ++i)
        cin >> ycoordinates[i];
    
    ll ans = 0;

    for(int i = 0; i < n; ++i){
        for (int j = i+1; j < n; ++j){
            ll dx = xcoordinates[i] - xcoordinates[j];
            ll dy = ycoordinates[i] - ycoordinates[j];
            ll res = (dx * dx)  + (dy * dy);
            ans = max(ans, res);
        }
    }
    cout << ans << "\n";
    return 0;
}