#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <set>

using namespace std;

const int nmax = 100000;
const char *infile = "trans.in";
const char *outfile = "trans.out";

typedef multiset<double> mSd;
typedef mSd::iterator dIt;

int N, K, P, cou;
mSd inSum, outSum;
double mas[nmax], ans[nmax];
long double sum;

int main()
{
    ifstream fin(infile);
    ofstream fout(outfile);
    int i;

    fin >> N >> P >> K;
    for (i = 0; i < P; i++)
    {
        fin >> mas[i];
        outSum.insert(mas[i]);
    }
    for (i = 0; i < K; i++)
    {
        dIt it = outSum.begin();
        sum += *it;
        inSum.insert(*it);
        outSum.erase(it);
    }

    cou = -1;
    for (i = P; i <= N; i++)
    {
        dIt iIt, oIt;
        cou++;
        ans[cou] = sum / K;

        double deletedElement = mas[i - P];
        iIt = inSum.end();
        iIt--;

        if (deletedElement <= *iIt)
        {
            sum -= deletedElement;
            inSum.erase(inSum.find(deletedElement));
        }
        else
            outSum.erase(outSum.find(deletedElement));

        fin >> mas[i];
        outSum.insert(mas[i]);
        oIt = outSum.begin();
        if (inSum.size() != K)
        {
            sum += *oIt;
            inSum.insert(*oIt);
            outSum.erase(oIt);
        }
    }

    for (int i = 0; i < cou; i++)
        fout << setiosflags(ios::fixed) << setprecision(6) << ans[i] << " ";
    fout << setiosflags(ios::fixed) << setprecision(6) << ans[cou] << endl;
    return 0;
}
