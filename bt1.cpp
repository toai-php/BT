/*
SV: Phung Huu Phuoc Toai
MSSV: 20183639
LANG: C++
Bai tap so 1: Tree compression
*/

#include<bits/stdc++.h>

using namespace std;

int n; int d[100] = {0};
int a[100][100];

int main(){
    ifstream cin("data.in");
    ofstream cout1("data.out");

    for(int i = 0; i < 100; i++)
        for(int j = 0; j < 100; j++)
            a[i][j] = -1;

    cin >> n;
    int p,q; int max = 0;
    for(int i = 1; i <= n; i++){
        cin >> p >> q;
        d[p]++; d[q]++;
        a[p][q] = 1;
        a[q][p] = 1;
        if(q > max) max = q;
        if(p > max) max = p;
    }
    int count = max-1;
    while(count > 0){
        bool check = true;
        for(int i = 1; i <= max; i++){
            if(d[i] == 1 && check == true){
                bool check2 = true;
                for(int j = 0; j < 100 && check2 == true; j++){
                    if(a[i][j] == 1){
                        cout1 << j << " ";
                        a[j][i] = -1;
                        d[j]--;
                    }
                }
                d[i]--;
                count--;
                check = false;
            }
        }
    }
    cout1 << endl;
    return 0;
}