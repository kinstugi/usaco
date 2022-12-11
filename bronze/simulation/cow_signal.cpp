#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ifstream fin("cowsignal.in");
    ofstream fout("cowsignal.out");
    int r, c, mag;
    fin >> r >> c >> mag;

    char res[r*mag][c*mag];
    for (int x = 0; x < mag*r; ++x)
        for (int y = 0; y < mag*c; ++y)
            res[x][y] = ' ';

    for (int x = 0; x < r; ++x){
        for (int y = 0; y < c; ++y){
            char tmp;
            fin >> tmp;
            int rr = x*mag, cc = y*mag;

            // cout << rr << " " << cc << "\n";
            for (int i = 0; i < mag; ++i)
                for(int k = 0; k < mag; ++k)
                    res[rr+i][cc+k] = tmp;
        }
    }

    for (int x = 0; x < mag*r; ++x){
        for (int y = 0; y < mag*c; ++y){
            fout << res[x][y] ;
        }
        fout << "\n";
    }

    return 0;
}