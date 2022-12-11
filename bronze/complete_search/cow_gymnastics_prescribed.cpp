#include <iostream>
using namespace std;

int main(){
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);

    int n, k;
    cin >> k >> n;
    int table[n+1][n+1];
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
            table[i][j] = 0;

    for (int session = 0; session < k; ++session){
        int tmp[n];
        for (int i = 0; i < n; ++i)
            cin >> tmp[i];
        
        for (int i = 0; i < n; ++i)
            for (int k = i+1; k < n; ++k)
                table[tmp[i]][tmp[k]]++;
    }

    for (int i = 0; i <= n; ++i)
        for (int k = 0; k <= n; ++k)
            cout << table[i][k] << " ";
        cout << "\n";
    return 0;
}