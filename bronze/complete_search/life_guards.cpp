#include<iostream>
#include<stack>
using namespace std;

bool isOverlapping(pair<int, int> a, pair<int, int> b){
    return (a.first <= b.first && b.first < a.second) || (b.first <= a.first && a.first < b.second);
}

int main(){
    freopen("lifeguards.in","r", stdin);
    freopen("lifeguards.out", "w", stdout);

    int N; cin >> N;
    pair<int, int> intervals[N];

    for (int i = 0; i < N; ++i)
        cin >> intervals[i].first >> intervals[i].second;
    
    sort(intervals, intervals + N);

    int ans = 0;
    for (int i = 0; i < N; ++i){
        stack<pair<int, int> > stk;
        int tmpCnt = 0;
        for (int j = 0; j < N; ++j){
            if (i == j) continue;

            if (!stk.empty() && isOverlapping(stk.top(), intervals[j])){
                pair<int, int> ta = stk.top(); stk.pop();
                ta.first = min(ta.first, intervals[j].first);
                ta.second = max(ta.second, intervals[j].second);
                stk.push(ta);
                continue;
            }else if (!stk.empty()){
                tmpCnt += (stk.top().second - stk.top().first);
                stk.pop();
            }
            stk.push(intervals[j]);
        }
        if (!stk.empty()){
            tmpCnt += (stk.top().second - stk.top().first);
        }
        ans = max(ans, tmpCnt);
    }
    cout << ans << "\n";
    return 0;
}