#include<iostream>
#define ll long long
using namespace std;

struct Rect{
    ll x1, y1, x2, y2;
    ll area(){
        if (x1 > x2 || y1 > y2) return 0;
        return (x2-x1) * (y2-y1);
    }
};

bool isCovered(int x, int y, Rect &a){
    return a.x1 <= x && x <= a.x2 && a.y1 <= y && y <= a.y2;
}

void cut(Rect &wp, Rect &bp){
    //bottom-left to top-left
    if (isCovered(wp.x1, wp.y1, bp) && isCovered(wp.x1, wp.y2, bp))
        wp.x1 = bp.x2;
    //bottom-left to bottom-right
    else if (isCovered(wp.x1, wp.y1, bp) && isCovered(wp.x2,wp.y1, bp))
        wp.y1 = bp.y2;
    //bottom-right to top-right
    else if (isCovered(wp.x2, wp.y1, bp) && isCovered(wp.x2,wp.y2, bp))
        wp.x2 = bp.x1;
    //top-right to top-left
    else if (isCovered(wp.x1, wp.y2, bp) && isCovered(wp.x2,wp.y2, bp))
        wp.y2 = bp.y1;
}

void solve(){
    Rect wp, bp1, bp2;
    cin >> wp.x1 >> wp.y1 >> wp.x2 >> wp.y2;
    cin >> bp1.x1 >> bp1.y1 >> bp1.x2 >> bp1.y2;
    cin >> bp2.x1 >> bp2.y1 >> bp2.x2 >> bp2.y2;
    
    cut(wp, bp1);
    cut(wp, bp2);
    long long a = wp.area();

    if (a < 1)
        cout << "NO\n";
    else
        cout <<"YES\n";
}

int main(){
    // freopen("wp.in", "r", stdin);
    int t = 1; //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}