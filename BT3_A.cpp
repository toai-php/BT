/*
Ho Ten: Phung Huu Phuoc Toai
MSSV: 20183639
Bai tap so 3-phan A
Lang: C++
*/
#include <bits/stdc++.h>

#define max 5757

using namespace std;

struct graph
{
    char data[6];
    vector<int> Ke;
    int LT;
    int dinh;
    int pre;
};

int b[max][max] = {0};
int lienthong = 0;

typedef struct graph data_type;
data_type a[max];
queue<data_type> que;

void LienThongBFS(data_type &temp)
{
    data_type pq;
    que.push(temp);
    temp.LT = lienthong;
    while (!que.empty())
    {
        pq = que.front();
        que.pop();
        for (int i = 0; i < pq.Ke.size(); i++)
        {
            if (a[pq.Ke[i]].LT == 0)
            {
                que.push(a[pq.Ke[i]]);
                a[pq.Ke[i]].LT = lienthong;
                a[pq.Ke[i]].pre = pq.dinh;
            }
        }
    }
}

void LienThongDFS(data_type &temp)
{
    temp.LT = lienthong;
    int ab;
    for (int i = 0; i < temp.Ke.size(); i++)
    {
        ab = temp.Ke[i];
        if (a[ab].LT == 0)
            LienThongDFS(a[ab]);
    }
}

bool compare(char a[6], char b[6])
{
    int check = 0;
    for (int i = 0; i <= 4 && check < 2; i++)
    {
        if (a[i] != b[i])
            ++check;
    }
    return check == 1;
}

int main()
{
    ifstream cin1("sgb-words.txt");
    for (int i = 0; i < max; i++)
    {
        cin1 >> a[i].data;
        a[i].dinh = i;
    }
    for (int i = 0; i < max; i++)
    {
        for (int j = 0; j < max; j++)
        {
            if (compare(a[i].data, a[j].data))
            {
                if (b[i][j] == 0)
                {
                    a[i].Ke.push_back(j);
                    a[j].Ke.push_back(i);
                    b[i][j] = b[j][i] = 1;
                }
            }
        }
    }
    char u[6], v[6];
    int loc = -1;
    for (int i = 0; i < max; i++)
        a[i].LT = 0;
    for (int i = 0; i < max; i++)
    {
        if (a[i].LT == 0)
        {
            lienthong++;
            LienThongBFS(a[i]);
        }
    }
    cout << "So tp lien thong: " << lienthong;
    cout << endl;
    cout << "Nhap u va v: \n";
    cin >> u >> v;
    for (int i = 0; i < max; i++)
        a[i].LT = 0;
    lienthong = 1;
    int stop = 1;
    for (int i = 0; i < max; i++)
        if (strcmp(a[i].data, u) == 0)
        {
            LienThongBFS(a[i]);
            stop = 0;
        }
    if (stop == 1)
    {
        cout << "khong tim thay u!\n";
        return 0;
    }
    for (int i = 0; i < max; i++)
    {
        if (strcmp(a[i].data, v) == 0 && a[i].LT != 0)
        {
            loc = a[i].pre;
        }
    }
    if (loc == -1)
        cout << "khong co duong di! hoac khong tim thay v!";
    else
    {
        cout << "duong di tu u den v (theo BFS): \n";
        cout << v << " ";
        bool check = true;
        while (check)
        {
            cout << " <-- " << a[loc].data;
            if (strcmp(a[loc].data, u) == 0)
                check = false;
            loc = a[loc].pre;
        }
    }
    cout << endl;
}
