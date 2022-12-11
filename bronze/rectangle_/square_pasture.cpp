#include<iostream>
using namespace std;

int main(){
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);

    int ax1, ay1, ax2, ay2, bx1, by1, bx2, by2;
    cin >> ax1 >> ay1 >> ax2 >> ay2;
    cin >> bx1 >> by1 >> bx2 >> by2;
    int x1 = min(ax1, bx1), y1 = min(ay1, by1);
    int x2 = max(ax2, bx2), y2 = max(ay2, by2);
    int ans = max(x2-x1, y2-y1);
    // cout << ax1 << " " << ay1 << " " << ax2 << " " << ay2 << "\n";
    cout << (ans * ans) << "\n";
    return 0;
}