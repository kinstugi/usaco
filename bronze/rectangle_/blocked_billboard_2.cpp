#include<iostream>
using namespace std;
struct Rect{
    int x1, y1, x2, y2;
};

int getArea(Rect &rect){
    return (rect.x2-rect.x1) * (rect.y2-rect.y1);
}

bool isOverlapping(Rect &r1, Rect &r2){
    bool res = ((r1.x1 <= r2.x1 && r2.x1 <= r1.x2) || (r2.x1 <= r1.x1 && r1.x1 <= r2.x2));
    if (res == false) return false;
    res = ((r1.y1 <= r2.y1 && r2.y1 <= r1.y2) || (r2.y1 <= r1.y1 && r1.y1 <= r2.y2));
    if (res == false) return false;
    return true;
}


int main(){
    freopen("billboard.in","r",stdin);
    freopen("billboard.out","w", stdout);
    
    Rect lawnMower; Rect food;
    cin >> lawnMower.x1 >> lawnMower.y1 >> lawnMower.x2 >> lawnMower.y2;
    cin >> food.x1 >> food.y1 >> food.x2 >> food.y2;

    if (isOverlapping(lawnMower, food)){
        Rect r;
        r.x1 = max(lawnMower.x1, food.x1), r.y1 = max(lawnMower.y1, food.y1);
        r.y2 = min(lawnMower.y2, food.y2), r.x2 = min(lawnMower.x2, food.x2);

        if (r.x1 == lawnMower.x1 && r.x2 == lawnMower.x2 && r.y1 == lawnMower.y1 && r.y2 == lawnMower.y2){
            cout << "0\n" ;
        }else if (r.x2 == lawnMower.x2 && r.y2 == lawnMower.y2 && r.y1 == lawnMower.y1){
            int tot = getArea(lawnMower) - getArea(r);
            cout << tot << "\n";
        }else if (r.x1 == lawnMower.x1 && r.y1 == lawnMower.y1 && r.y2 == lawnMower.y2){
            int tot = getArea(lawnMower) - getArea(r);
            cout << tot << "\n";
        }else{
            cout << getArea(lawnMower) << "\n";
        }
    }else{
        // not overlapping
        cout << getArea(lawnMower) << "\n";
    }

    return 0;
}