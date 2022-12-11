#include <iostream>
#include <vector>
using namespace std;

struct Line{
    pair<int, int> start, end;
    Line (pair<int, int> s, pair<int, int> e){
        start = s, end = e;
    }

    int getLen(){
        return (end.first - start.first) + (end.second - start.second);
    }
};

bool isConnected(pair<int, int> a, pair<int, int> b){
    return a.first == b.first && a.second == b.second;
}

int main(){
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    int N; cin >> N;
    vector<pair<int, int> > pts(N);
    vector<Line> parallelToX, parallelToY;

    for (int i = 0; i < N; ++i)
        cin >> pts[i].first >> pts[i].second;
    
    sort(pts.begin(), pts.end());

    for (int i = 0; i < N; ++i){
        for (int j = i+1; j < N; ++j){
            if (pts[i].first == pts[j].first){
                Line tmp(pts[i], pts[j]);
                parallelToY.push_back(tmp);
            }

            if (pts[i].second == pts[j].second){
                Line tmp(pts[i], pts[j]);
                parallelToX.push_back(tmp);
            }
        }
    }
    int ans = 0;
    for (auto xl: parallelToX){
        for (auto rl: parallelToY){
            if (isConnected(xl.start, rl.start) || isConnected(xl.start, rl.end) || isConnected(xl.end, rl.start) || isConnected(xl.end, rl.end)){
                ans = max(ans, xl.getLen() * rl.getLen());
            }
        }
    }
    cout << ans << "\n";
    return 0;
}