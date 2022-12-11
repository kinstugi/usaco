#include<iostream>
#include<fstream>
#include<algorithm>
#include<cmath>
using namespace std;

void check(int &spot, int a, int b){
    if (spot == a){
        spot = b;
        return;
    }
    if (spot == b)
        spot = a;
}

int main(){
    ifstream fin("shell.in");
    ofstream fout("shell.out");
    int n;
    fin >> n;
    int a1 = 1, b1 = 2, c1 = 3;
    int aCnt = 0, bCnt = 0, cCnt = 0; 
    int a, b, g;
    while(n--){
        fin >> a >> b >> g;
        check(a1, a, b);
        check(b1, a, b);
        check(c1, a, b);
        // cout << a1 << "\t" << b1 << "\t" << c1 << "\n";
        if (g == a1) aCnt++;
        if (g == b1) bCnt++;
        if (g == c1) cCnt++;
    }
    fout << max(aCnt, max(bCnt, cCnt)) << "\n";
    return 0;
}