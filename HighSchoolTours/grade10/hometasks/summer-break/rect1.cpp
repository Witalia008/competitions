#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <list>

using namespace std;

const char *infile = "rect1.in";
const char *outfile = "rect1.out";

class rect
{
public:
    int llx, lly, urx, ury, color;
    rect() {}
    rect(int llx, int lly, int urx, int ury, int clr) : llx(llx), lly(lly), urx(urx), ury(ury), color(clr)
    {
    }
};
typedef list<rect>::iterator listIter;

int a, b;
int colors[2501];
list<rect> rects;

inline void tryInsertRect(rect r, listIter i)
{
    if (r.llx < r.urx && r.lly < r.ury)
    {
        rects.insert(i, r);
        colors[r.color] += (r.urx - r.llx) * (r.ury - r.lly);
    }
}

inline void insertRect(rect r)
{
    listIter i = rects.begin();
    colors[r.color] += (r.urx - r.llx) * (r.ury - r.lly);

    while (i != rects.end())
    {
        if (i->llx >= r.llx && i->urx <= r.urx && i->lly >= r.lly && i->ury <= r.ury)
        {
            colors[i->color] -= (i->urx - i->llx) * (i->ury - i->lly);
            i = rects.erase(i);
        }
        else if (i->llx <= r.llx && i->lly <= r.lly && i->urx >= r.urx && i->ury >= r.ury)
        {
            colors[i->color] -= (i->urx - i->llx) * (i->ury - i->lly);
            tryInsertRect(rect(i->llx, i->lly, r.llx, i->ury, i->color), i);
            tryInsertRect(rect(r.llx, r.ury, i->urx, i->ury, i->color), i);
            tryInsertRect(rect(r.urx, i->lly, i->urx, r.ury, i->color), i);
            tryInsertRect(rect(r.llx, i->lly, r.urx, r.lly, i->color), i);
            *i = r;
            return;
        }
        else if (i->urx >= r.llx && i->urx <= r.urx && i->llx <= r.llx && i->lly <= r.ury && i->ury >= r.lly)
        {
            colors[i->color] -= (i->urx - i->llx) * (i->ury - i->lly);
            tryInsertRect(rect(r.llx, r.ury, i->urx, i->ury, i->color), i);
            tryInsertRect(rect(r.llx, i->lly, i->urx, r.lly, i->color), i);
            tryInsertRect(rect(i->llx, i->lly, r.llx, i->ury, i->color), i);
            i = rects.erase(i);
        }
        else if (i->llx >= r.llx && i->llx <= r.urx && i->urx >= r.urx && i->lly <= r.ury && i->ury >= r.lly)
        {
            colors[i->color] -= (i->urx - i->llx) * (i->ury - i->lly);
            tryInsertRect(rect(i->llx, r.ury, r.urx, i->ury, i->color), i);
            tryInsertRect(rect(i->llx, i->lly, r.urx, r.lly, i->color), i);
            tryInsertRect(rect(r.urx, i->lly, i->urx, i->ury, i->color), i);
            i = rects.erase(i);
        }
        else if (i->ury <= r.ury && i->ury >= r.lly && i->lly <= r.lly && i->urx >= r.llx && i->llx <= r.urx)
        {
            colors[i->color] -= (i->urx - i->llx) * (i->ury - i->lly);
            tryInsertRect(rect(i->llx, r.lly, r.llx, i->ury, i->color), i);
            tryInsertRect(rect(r.urx, r.lly, i->urx, i->ury, i->color), i);
            tryInsertRect(rect(i->llx, i->lly, i->urx, r.lly, i->color), i);
            i = rects.erase(i);
        }
        else if (i->lly >= r.lly && i->lly <= r.ury && i->ury >= r.ury && i->urx >= r.llx && i->llx <= r.urx)
        {
            colors[i->color] -= (i->urx - i->llx) * (i->ury - i->lly);
            tryInsertRect(rect(i->llx, i->lly, r.llx, r.ury, i->color), i);
            tryInsertRect(rect(r.urx, i->lly, i->urx, r.ury, i->color), i);
            tryInsertRect(rect(i->llx, r.ury, i->urx, i->ury, i->color), i);
            i = rects.erase(i);
        }
        else if (i->llx <= r.llx && i->urx >= r.urx && i->lly >= r.lly && i->ury <= r.ury)
        {
            colors[i->color] -= (i->urx - i->llx) * (i->ury - i->lly);
            tryInsertRect(rect(i->llx, i->lly, r.llx, i->ury, i->color), i);
            tryInsertRect(rect(r.urx, i->lly, i->urx, i->ury, i->color), i);
            i = rects.erase(i);
        }
        else if (i->llx >= r.llx && i->urx <= r.urx && i->lly <= r.lly && i->ury >= r.ury)
        {
            colors[i->color] -= (i->urx - i->llx) * (i->ury - i->lly);
            tryInsertRect(rect(i->llx, r.ury, i->urx, i->ury, i->color), i);
            tryInsertRect(rect(i->llx, i->lly, i->urx, r.lly, i->color), i);
            i = rects.erase(i);
        }
        else
            i++;
    }

    rects.push_back(r);
}

int main()
{
    ifstream fin(infile);
    ofstream fout(outfile);

    int n, i;
    rect r;

    fin >> a >> b >> n;
    rects.push_back(rect(0, 0, a, b, 0));
    colors[0] = a * b;

    for (i = 0; i < n; i++)
    {
        fin >> r.llx >> r.lly >> r.urx >> r.ury >> r.color;
        r.color--;
        insertRect(r);
    }

    for (i = 0; i <= 2500; i++)
        if (colors[i])
            fout << i + 1 << " " << colors[i] << endl;
    return 0;
}
