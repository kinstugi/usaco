#include<iostream>
#include <vector>
using namespace std;

bool isCutting(vector<int> a, vector<int> b){
    return a[0] <= b[0] && b[0] < a[1] && a[1] < b[1];
}

int main(){
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);
    string mp; cin >> mp; int i = 0;
    vector<vector<int> > hset(26, vector<int>(2, -1));
    for (char ch: mp){
        if (hset[ch-'A'][0] == -1)
            hset[ch-'A'][0] = i++;
        else
            hset[ch-'A'][1] = i++;
    }
    int ans = 0;
    for (vector<int> bc: hset){

        if (bc[0] == bc[1]-1) continue;

        for (vector<int> ac: hset){
            if (ac[0] == bc[0] && ac[1] == bc[1]) continue;
            if (isCutting(ac, bc) || isCutting(bc, ac)){
                ans++;
            }
        }
    }
    cout << (ans/2) << "\n";
    return 0;
}