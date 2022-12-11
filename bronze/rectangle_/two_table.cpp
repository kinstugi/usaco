#include<iostream>
using namespace std;

void solve(){
    int W, H; 
    cin >> W >> H;
    int x1, y1, x2, y2; 
    cin >> x1 >> y1 >> x2 >> y2;
    int w,  h; 
    cin >> w >> h;

    int tW = x2 - x1, tH = y2 - y1;
    if ((tW + w) > W && (tH+h) > H){
        cout << -1 << "\n"; return;
    }else if ((tH+h) > H){
        if (x1 >= w || (W-x2) >= w){
            cout << 0 <<  "\n";
        }else{
            int ans = w - x1;
            ans = min(ans, w - (W-x2));
            cout << ans << "\n";
        }
    }else if ((tW+w) > W){
        if (y1 >= h || (H-y2) >= h){
            cout << 0 << "\n";
        }else{
            int ans = (h - y1);
            ans = min(ans, h - (H-y2));
            cout << ans << "\n";
        }
    }else{
        if (y1 >= h || (H-y2) >= h || x1 >= w || (W-x2) >= w){
            cout << 0 << "\n";
        }else{
            int ans = min(h - (H-y2), w - (W-x2));
            ans = min(ans, min(h - y1, w - x1));
            cout << ans << "\n";
        }
    }


}

int main(){
    // freopen("input.in", "r", stdin);
    int t; cin >> t;
    while(t--)
        solve();
    return 0;
}