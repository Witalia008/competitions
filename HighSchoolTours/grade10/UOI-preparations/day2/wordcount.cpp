#include <stdio.h>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#define nmax 15000

using namespace std;

struct TList
{
    int Dest, Next;
    string Name;
};

TList List[nmax + 1];
int Head[nmax + 1];
int P[nmax + 1];
string S;
int N, en, Ans, Len;

inline void Add(int u, int v, string n)
{
    en++;
    List[en].Dest = v;
    List[en].Next = Head[u];
    List[en].Name = n;
    Head[u] = en;
}

inline void kmp(int L)
{
    int k = P[L - 1];
    int le = S.length();
    for (int i = L; i < le; i++)
    {
        while (k > 0 && S[i] != S[k])
            k = P[k - 1];
        if (S[k] == S[i])
            k++;
        P[i] = k;
        if (k == Len)
            Ans++;
    }
}

void DFS(int i, int len)
{
    kmp((len == 0) ? 1 : len);
    int j = Head[i];
    while (j)
    {
        int x = S.length();
        S += List[j].Name;
        DFS(List[j].Dest, x);
        S.erase(x - 1, List[j].Name.length());
        j = List[j].Next;
    }
}

//char buf[nmax*nmax/10];

int main()
{
    ifstream cin("wordcount.in");
    ofstream cout("wordcount.out");
    //setbuf (stdin, buf);
    cin >> N;
    for (int i = 1; i < N; i++)
    {
        int s, f;
        string n;
        cin >> s >> f >> n;
        Add(s, f, n);
    }
    cin >> S;
    S += "#";
    Len = S.length() - 1;
    DFS(0, 0);
    cout << Ans << endl;
    cin.close();
    cout.close();
    return 0;
}
