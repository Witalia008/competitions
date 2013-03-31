#include <fstream>
#include <string>

using namespace std;

ifstream fin("a.in");
ofstream fout("a.out");

#define NMAX 1001

struct _1
{
    string A, B;
    int t;
};

int N, d, cnt;
_1 A[NMAX], Ans[NMAX];

int main()
{
    fin >> N >> d;
    cnt = 0;
    for (int i = 0; i < N; i++)
    {
        fin >> A[i].A >> A[i].B >> A[i].t;
        bool fr, is;
        fr = is = false;
        for (int j = 0; j < i; j++)
            if (A[j].A == A[i].B && A[j].B == A[i].A)
                if (A[i].t - A[j].t > 0 && A[i].t - A[j].t <= d)
                    is = true;
        if (is)
        {
            for (int j = 0; j < cnt; j++)
                if ((Ans[j].A == A[i].A && Ans[j].B == A[i].B) || (Ans[j].A == A[i].B && Ans[j].B == A[i].A))
                    fr = true;
            if (!fr)
                Ans[cnt++] = A[i];
        }
    }
    fout << cnt << endl;
    for (int i = 0; i < cnt; i++)
        fout << Ans[i].A << " " << Ans[i].B << endl;
    return 0;
}
