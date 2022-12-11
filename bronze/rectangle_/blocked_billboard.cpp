#include<iostream>
#define ll long long
using namespace std;

ll getArea(int x1, int y1, int x2, int y2){
    int area = (x2-x1) * (y2-y1);
    if (area < 0) return 0;
    return area;
}

bool isOverlapping(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2){
    return (ax1 <= bx1 && bx1 <= ax2) || (bx1 <= ax1 && ax1 <= bx2);
}

int main(){
    freopen("billboard.in","r", stdin);
    freopen("billboard.out", "w", stdout);
    
    int ax1, ay1, ax2, ay2;
    int bx1, by1, bx2, by2;
    int cx1, cy1, cx2, cy2;

    cin >> ax1 >> ay1 >> ax2 >> ay2;
    cin >> bx1 >> by1 >> bx2 >> by2;
    cin >> cx1 >> cy1 >> cx2 >> cy2;

    ll tot = getArea(ax1, ay1, ax2, ay2) + getArea(bx1, by1, bx2, by2);
    if (isOverlapping(cx1,cy1,cx2,cy2, ax1,ay1,ax2,ay2))
        tot -= getArea(max(ax1,cx1), max(ay1, cy1), min(ax2,cx2), min(ay2,cy2));

    if (isOverlapping(bx1,by1,bx2,by2, cx1,cy1,cx2,cy2))
        tot -= getArea(max(bx1,cx1), max(by1, cy1), min(bx2,cx2), min(by2,cy2));

    cout << tot << "\n";
    return 0;
}