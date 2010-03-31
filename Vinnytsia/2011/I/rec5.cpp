#include <stdio.h>
#include <cstdlib>
#include <iostream>

using namespace std;

typedef long long LL;

struct TRect
{
    LL lx, ly, ux, uy;
};

void Scan(TRect &a)
{
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    a.lx = min(x1, x2);
    a.ly = min(y1, y2);
    a.ux = max(x1, x2);
    a.uy = max(y1, y2);
}

LL common(LL lx1, LL ux1, LL lx2, LL ux2)
{
    if (ux1 <= lx2 || ux2 <= lx1)
        return 0;
    if (ux1 <= ux2 && lx1 >= lx2)
        return ux1 - lx1;
    if (ux2 <= ux1 && lx2 >= lx1)
        return ux2 - lx2;
    if (lx1 <= lx2 && ux1 >= lx2 && ux1 <= ux2)
        return ux1 - lx2;
    if (lx2 <= lx1 && ux2 >= lx1 && ux2 <= ux1)
        return ux2 - lx1;
}

TRect fst, snd;

int main()
{
    Scan(fst);
    Scan(snd);

    /*if (fst.lx <= snd.lx && fst.ly <= snd.ly && fst.ux >= snd.ux && fst.uy >= snd.uy)
        cout << (snd.ux - snd.lx) * (snd.uy - snd.ly) << endl;
    else if (snd.lx <= fst.lx && snd.ly <= fst.ly && snd.ux >= fst.ux && snd.uy >= fst.uy)
        cout << (fst.ux - fst.lx) * (fst.uy - fst.ly) << endl;
    else if (fst.lx <= snd.lx && fst.ux >= snd.lx && fst.ux <= snd.ux && fst.uy >= snd.ly && fst.ly <= snd.uy)
        cout << (fst.ux - snd.lx) * (min(fst.uy, snd.uy) - max(fst.ly, snd.ly)) << endl;
    else if (fst.lx >= snd.lx && fst.lx <= snd.ux && fst.ux >= snd.ux && fst.uy >= snd.ly && fst.ly <= snd.uy)
        cout << (snd.ux - fst.lx) * (min(fst.uy, snd.uy) - max(fst.ly, snd.ly)) << endl;
    else if (fst.uy >= snd.uy && fst.ly >= snd.ly && fst.ly <= snd.uy && fst.ux >= snd.lx && fst.lx <= snd.ux)
        cout << (snd.uy - fst.ly) * (min(fst.ux, snd.ux) - max (fst.lx, snd.lx)) << endl;
    else if (fst.ly <= snd.ly && fst.uy >= snd.ly && fst.uy <= snd.uy && fst.ux >= snd.lx && fst.lx <= snd.ux)
        cout << (fst.uy - snd.ly) * (min(fst.ux, snd.ux) - max (fst.lx, snd.lx)) << endl;
    else if (fst.lx <= snd.lx && fst.ux >= snd.ux && fst.uy <= snd.uy && fst.ly >= snd.ly)
        cout << (fst.uy - fst.ly) * (snd.ux - snd.lx) << endl;
    else if (fst.lx >= snd.lx && fst.ux <= snd.ux && fst.ly <= snd.ly && fst.uy >= snd.uy)
        cout << (fst.ux - fst.lx) * (snd.uy - snd.ly) << endl;
    else
        cout << "0\n";*/
    cout << common(fst.lx, fst.ux, snd.lx, snd.ux) * common(fst.ly, fst.uy, snd.ly, snd.uy) << endl;
    return 0;
}
