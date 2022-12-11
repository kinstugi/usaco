#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ifstream fin("speeding.in");
    ofstream fout("speeding.out");
    int n, m, st = 0;
    int legit[100];
    int bessie[100];

    fin >> n >> m;
    int distance, speedLimit;

    while(n--){
        fin >> distance >> speedLimit;
        for (int i = st; i < st + distance; ++i)
            legit[i] =  speedLimit;
        st += distance;
    }

    st = 0;
    while(m--){
        fin >> distance >> speedLimit;
        for (int i = st; i < st + distance; ++i)
            bessie[i] = speedLimit;
        st += distance;
    }
    int ans = 0;
    for (int i = 0; i < 100; ++i){
        int d = bessie[i] - legit[i];
        if (ans < d)
            ans = d;
    }
    fout << ans << "\n";   
    return 0;
}