#include<iostream>
#include<fstream>
#include<set>
#include<algorithm>
using namespace std;

int main(){
    ifstream fin("blist.in");
    ofstream fout("blist.out");
    multiset<pair<int, int> > arr;
    int n;
    fin >> n;
    while(n--){
        int st, ed, b;
        fin >> st >> ed >> b;

        arr.insert(make_pair(st, -b));
        arr.insert(make_pair(ed, b));
    }
    int ans = 0, cnt = 0;
    for (auto item: arr){
        cnt += item.second;
        ans = min(ans, cnt);
    }
    fout << (ans * -1) << "\n";
    return 0;
}