#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

bool commonChar(string a, string b){
    for (char ch: a){
        for (char bh: b){
            if (ch == bh) return true;
        }
    }
    return false;
}

int main(){
    ifstream fin("cownomics.in");
    ofstream fout("cownomics.out");
    int N, M;
    fin >> N >> M;
    vector<string> spottedCows(M, "");
    vector<string> plainCows(M, "");

    for (int i = 0; i < N; ++i){
        string tmp; fin >> tmp;
        for (int j = 0; j < M; ++j)
            spottedCows[j] += tmp[j];
    }

    for (int i = 0; i < N; ++i){
        string tmp; fin >> tmp;
        for (int j = 0; j < M; ++j)
            plainCows[j] += tmp[j];
    }
    int ans = 0;
    for (int i = 0; i < M; ++i){
        if (!commonChar(spottedCows[i], plainCows[i])) ans++;
    }
    fout << ans << endl;
    return 0;
}