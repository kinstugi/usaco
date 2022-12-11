#include<iostream>
#include<fstream>
#define ll long long
using namespace std;

int main(){
    ifstream fin("mixmilk.in");
    ofstream fout("mixmilk.out");

    ll b1Cap, b2Cap, b3Cap;
    ll b1Amt, b2Amt, b3Amt;

    fin >> b1Cap >> b1Amt;
    fin >> b2Cap >> b2Amt;
    fin >>b3Cap >> b3Amt;

    //simulate the process
    int t = 100;
    while(t){
        int d2 = b2Cap - b2Amt;
        if (d2 >= b1Amt)
            b2Amt += b1Amt, b1Amt = 0;
        else
            b2Amt += d2, b1Amt -= d2;
        
        if (--t == 0) break;

        int d3 = b3Cap - b3Amt;
        if (d3 >= b2Amt)
            b3Amt += b2Amt, b2Amt = 0;
        else
            b3Amt += d3, b2Amt -= d3;
            
        if (--t == 0) break;
        
        int d1 = b1Cap - b1Amt;
        if (d1 >= b3Amt)
            b1Amt += b3Amt, b3Amt = 0;
        else
            b1Amt += d1, b3Amt -= d1;
        t--;
    }
    fout << b1Amt << "\n";
    fout << b2Amt << "\n";
    fout << b3Amt << "\n";
    return 0;
}