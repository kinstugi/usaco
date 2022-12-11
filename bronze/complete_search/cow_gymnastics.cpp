#include <iostream>
#include <set>
using namespace std;

int main(){
    
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);

    int n, k;
    cin >> k >> n;
    set<pair<int, int> > hset;

    for (int i = 0; i < k; ++i){
        int tmp[n];
        for (int k = 0; k < n; ++k)
            cin >>tmp[k];
        
        if (i == 0){
            for (int x = 0; x < n; ++x)
                for (int y = x+1; y < n; ++y)
                    hset.insert(make_pair(tmp[x],tmp[y]));
        }else{
            for (int x = 0; x < n; ++x)
                for (int y = x+1; y < n; ++y){
                    pair<int, int> aTemp = make_pair(tmp[y], tmp[x]);
                    if (hset.count(aTemp)){
                        hset.erase(aTemp);
                    }
                }
        }
    }
    cout << hset.size() << "\n";
    return 0;
}