#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ifstream fin("lostcow.in");
    ofstream fout("lostcow.out");

    int x, y, cnt = 0;
    fin >> x >> y;
    int d = 1;
    while(x+d != y){
        
        d *= -2;
    }
    return 0;
}