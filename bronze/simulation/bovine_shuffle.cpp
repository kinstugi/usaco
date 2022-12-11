#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

int main(){
    ifstream fin("shuffle.in");
    ofstream fout("shuffle.out");

    int n;
    fin >> n;
    int shuffleArray[n];
    int cows[n];
    int initial[n];

    for(int i = 0; i < n; ++i)
        fin >> shuffleArray[i];
    
    for (int i = 0; i < n; ++i)
        fin >> cows[i];

    for (int i = 0; i < n; ++i)
        initial[i] = i + 1;
    
    for (int i = 0; i < 3; ++i){
        int tmp[n];
        for (int k = 0; k < n; ++k)
            tmp[shuffleArray[k]-1] = initial[k];
        
        for(int k = 0; k < n; ++k)
            initial[k] = tmp[k];
    }
    pair<int, int> final[n];
    for (int i = 0; i < n; ++i)
        final[i] = make_pair(initial[i], cows[i]);
    sort(final, final+n);
    for (auto item: final)
        fout << item.second << "\n";
    
    fin.close();
    fout.close();
    return 0;
}
