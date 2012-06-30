#include <stdio.h>
#include <cstdlib>

using namespace std;

const char *infile = "score.dat";
const char *outfile = "score.sol";
const int nmax = 251;

class cell
{
public:
    int x, y;
    cell() {}
    cell(int x, int y) : x(x), y(y) {}
    cell operator+(cell b)
    {
        return cell(this->x + b.x, this->y + b.y);
    }
    bool operator==(cell b)
    {
        return (x == b.x && y == b.y);
    }
    bool operator!=(cell b)
    {
        return (x != b.x || y != b.y);
    }
    ~cell() {}
};

int N, top;
char A[nmax][nmax], A1[nmax][nmax];
bool used[nmax][nmax];
char curPlayer;
cell finish, Go;
cell stack[nmax * nmax];
cell toStack[nmax * nmax];

cell noCell = cell(-1, -1);

bool isGood(cell a)
{
    return (a.x >= 0 && a.x < N && a.y >= 0 && a.y < N);
}

bool isNeeded(cell a)
{
    return (A[a.x][a.y] == curPlayer && !used[a.x][a.y]);
}

cell getRight(cell a)
{
    if (a.x == -1)
        return cell(0, 1);
    if (a.x == 1)
        return cell(0, -1);
    if (a.y == -1)
        return cell(-1, 0);
    return cell(1, 0);
}

cell nextPrior(cell Where, cell to)
{
    cell newTo = getRight(to);
    Go = newTo + Where;
    if (isGood(Go) && isNeeded(Go))
        return Go;
    Go = to + Where;
    if (isGood(Go) && isNeeded(Go))
        return Go;
    Go = cell(-newTo.x, -newTo.y) + Where;
    if (isGood(Go) && isNeeded(Go))
        return Go;
    return noCell;
}

void search(cell cur, cell to)
{
    top = 0;
    stack[0] = cur;
    toStack[0] = to;
    cell v, _to;
    while (top >= 0)
    {
        v = stack[top];
        _to = toStack[top];
        used[v.x][v.y] = true;
        if (v == finish)
            return;
        Go = nextPrior(v, _to);
        if (Go != noCell)
        {
            top++;
            stack[top] = Go;
            toStack[top] = cell(Go.x - v.x, Go.y - v.y);
        }
        else
            top--;
    }
}

void outPole()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%c", A[i][j]);
        printf("\n");
    }
}

void setWay()
{
    for (int i = 0; i <= top; i++)
        A[stack[i].x][stack[i].y] = curPlayer - 1;
    cell right;
    for (int i = 1; i < top; i++)
    {
        right = getRight(toStack[i]);
        if (toStack[i] == toStack[i + 1])
            A1[stack[i].x + right.x][stack[i].y + right.y] = curPlayer + 1;
        if (toStack[i + 1] == cell(-right.x, -right.y))
        {
            A1[stack[i].x + right.x][stack[i].y + right.y] = curPlayer + 1;
            A1[stack[i].x + toStack[i].x][stack[i].y + toStack[i].y] = curPlayer + 1;
        }
    }
    if (curPlayer == 'W')
    {
        if (A[1][0] != curPlayer - 1)
            A1[1][0] = curPlayer + 1;
        if (A[1][N - 1] != curPlayer - 1)
            A1[1][N - 1] = curPlayer + 1;
    }
    else
    {
        if (A[N - 2][N - 1] != curPlayer - 1)
            A1[N - 2][N - 1] = curPlayer + 1;
        if (A[N - 2][0] != curPlayer - 1)
            A1[N - 2][0] = curPlayer + 1;
    }
}

int getAns(int s, int f, int _i)
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            A1[i][j] = A[i][j];
    setWay();
    //outPole();
    int res = 0;
    bool isIn;
    for (int j = 0; j < N; j++)
    {
        isIn = true;
        for (int i = s; i != f + _i; i += _i)
        {
            if (A1[i][j] == curPlayer + 1)
                isIn = false;
            if (A[i][j] == curPlayer - 1)
                isIn = true;
            if (isIn)
                res++;
        }
    }
    return res;
}

int main()
{
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    scanf("%d\n", &N);
    for (int i = 0; i < N; i++)
        gets(A[i]);

    curPlayer = 'W';
    finish = cell(0, N - 1);
    search(cell(0, 0), cell(0, 1));
    printf("%d\n", getAns(0, N - 1, 1));

    curPlayer = 'B';
    finish = cell(N - 1, 0);
    search(cell(N - 1, N - 1), cell(0, -1));
    printf("%d\n", getAns(N - 1, 0, -1));
    return 0;
}
