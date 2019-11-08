/*
Ho Ten: Phung Huu Phuoc Toai
MSSV: 20183639
Bai tap so 3-phan B
Lang: C++
*/
#include <bits/stdc++.h>
#define max 5757

using namespace std;

struct graph
{
    char data[6];
    int dinh;
    int LT;
    int pre;
    vector<int> ke;
    vector<int> nguoc;
};

typedef struct graph data_type;
data_type a[max];
int b[max][max] = {0};
int lienthong = 0;
vector<int> que;

void BFS(data_type &temp)
{
    data_type pq;
    queue<data_type> que2;
    que2.push(temp);
    temp.LT = 1;
    while (!que2.empty())
    {
        pq = que2.front();
        que2.pop();
        for (int i = 0; i < pq.ke.size(); i++)
        {
            if (a[pq.ke[i]].LT == 0)
            {
                que2.push(a[pq.ke[i]]);
                a[pq.ke[i]].LT = 1;
                a[pq.ke[i]].pre = pq.dinh;
            }
        }
    }
}

void DFS(data_type &temp)
{
    temp.LT = -1;
    int ab;
    for (int i = 0; i < temp.nguoc.size(); i++)
    {
        ab = temp.nguoc[i];
        if (a[ab].LT == 0)
            DFS(a[ab]);
    }
    que.push_back(temp.dinh);
}

void lienthongDFS(data_type &temp)
{
    temp.LT = lienthong;
    for (int i = 0; i < que.size(); i++)
        if (temp.dinh == que[i])
            que[i] = -1;
    for (int i = 0; i < temp.ke.size(); i++)
    {
        if (a[temp.ke[i]].LT == -1)
            lienthongDFS(a[temp.ke[i]]);
    }
}

bool compare(char a[6], char b[6])
{
    for (int i = 1; i < 5; i++)
    {
        if (a[i] != b[0] && a[i] != b[1] && a[i] != b[2] && a[i] != b[3] && a[i] != b[4])
            return false;
    }
    return true;
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
            if (compare(a[i].data, a[j].data) && i != j)
            {
                b[i][j] = 1;
                a[i].ke.push_back(j);
                a[j].nguoc.push_back(i);
            }
        }
    }
    for (int i = 0; i < max; i++)
        a[i].LT = 0;
    for (int i = 0; i < max; i++)
    {
        if (a[i].LT == 0)
        {
            DFS(a[i]);
        }
    }
    int k = que.size() - 1;
    while (que[0] != -1)
    {
        while (que[k] == -1 && k > 0)
            k--;
        lienthong++;
        lienthongDFS(a[que[k]]);
    }
    cout << "1. so thanh phan lien thong manh: " << lienthong << endl;
    char u[6], v[6];
    cout << "2. tim cac dinh co cung lien thong manh voi u\n";
    cout << "nhap vao 1 tu: ";
    cin >> u;
    int check = 1;
    for (int i = 0; i < max; i++)
    {
        if (strcmp(a[i].data, u) == 0)
        {
            int ij = 0;
            check = 0;
            for (int j = 0; j < max; j++)
                if (a[j].LT == a[i].LT && i != j)
                    ij++;
            if (ij == 0)
                cout << "ko co dinh nao khac ngoai u\n";
            else
            {
                for (int j = 0; j < max; j++)
                    if (a[j].LT == a[i].LT && i != j)
                        cout << a[j].data << " ";
            }
        }
    }
    if (check == 1)
        cout << "khong tim thay u!\n";
    cout << endl;
    cout << "3. tim duong di u toi v bang bfs\n";
    cout << "nhap u va v: ";
    cin >> u >> v;
    check = 1;
    for (int i = 0; i < max; i++)
        a[i].LT = 0;
    for (int i = 0; i < max; i++)
    {
        if (strcmp(a[i].data, u) == 0)
        {
            BFS(a[i]);
            check = 0;
        }
    }
    if (check == 1)
        cout << "khong tim thay u!\n";
    else
    {
        int loc = -1;
        for (int i = 0; i < max; i++)
        {
            if (strcmp(a[i].data, v) == 0 && a[i].LT != 0)
                loc = a[i].pre;
        }
        if (loc == -1)
            cout << "khong co duong di!\n";
        else
        {
            cout << "duong di tu u toi v:\n";
            cout << v << " ";
            bool check2 = true;
            while (check2)
            {
                cout << " <-- " << a[loc].data;
                if (strcmp(a[loc].data, u) == 0)
                    check2 = false;
                loc = a[loc].pre;
            }
        }
    }
}