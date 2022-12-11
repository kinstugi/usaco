#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ifstream fin("paint.in");
    ofstream fout("paint.out");
    int a, b, c, d;
    
    fin >> a >> b >> c >> d;
    int tot = (b-a) + (d-c);
    if ((a <= c && c <= b) || (c <= a && a <= d)){
        int x = min(b,d) - max(a, c);
        tot -= x;
    }
    fout << tot << "\n";
    return 0;
}