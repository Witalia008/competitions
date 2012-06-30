/*
PROG: fence8
LANG: C++
*/
#include <fstream>
#include <algorithm>

using namespace std;

const char *infile = "fence8.in";
const char *outfile = "fence8.out";

const int maxN = 50;
const int maxR = 1023;
const int maxcheck = 5000000;

int n, r;
int boards[maxN], rails[maxR];

int maxrailcnt = 0, railcnt = 0, check;

void cut_rails(int i, int st)
{
    int j;
    int railnum = i;
    if (i >= r)
    {
        if (railcnt > maxrailcnt)
            maxrailcnt = railcnt;
        return;
    }
    if (maxrailcnt >= r)
        return;
    if (++check >= maxcheck)
        return;
    for (; i < r; i++)
    {
        if (railcnt + r - i <= maxrailcnt)
            return;
        if (i && rails[i] == rails[i - 1] && i > railnum)
            continue;
        for (j = 0; j < n; j++)
            if (boards[j] == rails[i])
            {
                railcnt++;
                boards[j] = boards[--n];
                cut_rails(i + 1, j);
                boards[n++] = boards[j];
                boards[j] = rails[i];
                railcnt--;
                return;
            }
        if (i && rails[i] == rails[i - 1])
            j = st;
        else
            j = 0;
        for (; j < n; j++)
        {
            if (boards[j] >= rails[i])
            {
                boards[j] -= rails[i];
                railcnt++;
                if (boards[j] < rails[r - 1])
                {

                    swap(boards[j], boards[--n]);
                    cut_rails(i + 1, j);
                    swap(boards[j], boards[n++]);
                }
                else
                    cut_rails(i + 1, j);
                railcnt--;
                boards[j] += rails[i];
            }
        }
    }
}

void greedy_init()
{
    int i, j, sum;
    for (i = 0, maxrailcnt = 0, j = r - 1; i < n; i++, j++)
        for (sum = 0; j >= 0;)
            if (sum <= boards[i])
            {
                if (sum)
                    maxrailcnt++;
                sum += rails[j--];
            }
            else
                break;
}

int main()
{
    int i, max, sum;
    ifstream ifs(infile);
    ofstream ofs(outfile);

    ifs >> n;
    for (i = 0, max = 0, sum = 0; i < n; i++)
    {
        ifs >> boards[i];
        if (boards[i] > max)
            max = boards[i];
        sum += boards[i];
    }
    ifs >> r;
    for (i = 0; i < r; i++)
        ifs >> rails[i];
    ifs.close();

    sort(rails, rails + r);
    for (i = 0; i < n; i++)
        if (boards[i] < rails[0])
        {
            sum -= boards[i];
            boards[i] = boards[n];
            n--;
            i--;
        }
    sort(boards, boards + n);
    for (; rails[r - 1] > max; r--)
        ;
    for (i = 0; i < r && sum >= 0; i++)
        sum -= rails[i];
    if (sum < 0)
        r = i - 1;
    for (i = 0; i < r / 2; i++)
        swap(rails[i], rails[r - i - 1]);
    for (i = 0; i < n / 2; i++)
        swap(boards[i], boards[n - i - 1]);
    greedy_init();
    cut_rails(0, 0);

    ofs << maxrailcnt << endl;

    return 0;
}
