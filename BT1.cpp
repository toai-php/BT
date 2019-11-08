/*
SV: Phung Huu Phuoc Toai
MSSV: 20183639
LANG: C++
Bai tap so 1: Tree compression
*/

#include<bits/stdc++.h>
#define MAX 100000

using namespace std;

int n;
int a[MAX][2] = {0};

int main(){
    ifstream cin("data.in");
    ofstream cout1("data.out");

    
    cin >> n;
    int p,q;
    for(int i = 1; i <= n; i++){
        cin >> p >> q;
        a[p][0]++; a[p][1]+= q;
        a[q][0]++; a[q][1]+= p;        
    }
    int count = n-1;
    bool check;
    while(count){
        check = true;
        // int temp;
        for(int i = 1; i <= n && check == true; i++){
                if(a[i][0] == 1){
                    cout1 << a[i][1] << " ";
                    a[i][0] = 0; a[a[i][1]][0]--;
                    a[a[i][1]][1] -= i;
                    count--;
                    check = false;
                }
        }
    }
    cout1 << endl;
    return 0;
}
