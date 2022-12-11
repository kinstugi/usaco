#include<iostream>
using namespace std;
struct Rect{
    int x1, y1, x2, y2;
};

bool isCovered(int x, int y, Rect &board){
    return board.x1 <= x && x >= board.x2 && board.y1 <= y && y <= board.y2;
}

int main(){
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    Rect lawnmower, food;
    cin >> lawnmower.x1 >> lawnmower.y1 >> lawnmower.x2 >> lawnmower.y2;
    cin >> food.x1 >> food.y1 >> food.x2 >> food.y2;
    int cnt = 0;
    
    if (isCovered(lawnmower.x1, lawnmower.y1, food)) ++cnt;
    if (isCovered(lawnmower.x1, lawnmower.y2, food)) ++cnt;
    if (isCovered(lawnmower.x2, lawnmower.y1, food)) ++cnt;
    if (isCovered(lawnmower.x2, lawnmower.y2, food)) ++cnt;

    if (cnt < 2)
        cout << (lawnmower.x2 - lawnmower.x1) * (lawnmower.y2 - lawnmower.y1) <<"\n";
    else if (cnt == 4)
        cout << 0 << "\n";
    else{
        int x1 = max(lawnmower.x1, food.x1), y1 = max(lawnmower.y1, food.y1);
        int x2 = min(lawnmower.x2, food.x2), y2 = min(lawnmower.y2, food.y2);
        int ans = (lawnmower.x2 - lawnmower.x1) * (lawnmower.y2 - lawnmower.y1);
        ans -= ((x2-x1)*(y2-y1));
        cout << ans << "\n";
    }
    return 0;
}