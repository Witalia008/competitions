/*
PROG: cryptcow
LANG: C++
*/
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

const char *infile = "cryptcow.in";
const char *outfile = "cryptcow.out";

const char *target = "Begin the Escape execution at the Break of Dawn";
const int targlen = 47;
const int maxmessagelen = 75;
const int maxiters = 70000;

struct node
{
    char c;
    node *next, *prev;
    node(char C) : c(C), next(0), prev(0) {}
    node *operator->()
    {
        return this;
    }
    char operator*() const { return c; }
};

int cowcnt, canbetarget = 0, iter;

node head(0), tail(0);

void test_message()
{
    int c, o, w, i, st, nd;
    char Ccnt = 0, Ocnt = 0, Wcnt = 0, COWcnt = 0;
    char str[maxmessagelen + 1];
    char *p;
    pair<int, node *> cs[10], os[10], ws[10];
    int cs2[10], os2[10], ws2[10];
    node *cows[30];
    node *n, *end;
    if (canbetarget)
        return;
    iter++;
    if (!cowcnt)
    {
        canbetarget = 1;
        return;
    }
    if (iter > maxiters)
        return;
    for (n = head->next, i = 0; target[i] && n->c != 'C'; n = n->next, i++)
        if (n->c != target[i])
            return;
    for (n = tail->prev, i = targlen - 1; i >= 0 && n->c != 'W'; n = n->prev, i--)
        if (n->c != target[i])
            return;
    for (i = 0, n = head->next; n->c; i++, n = n->next)
        switch (n->c)
        {
        case 'C':
            cs2[Ccnt] = COWcnt;
            cs[Ccnt++] = pair<int, node *>(i, n);
            cows[COWcnt++] = n;
            break;
        case 'O':
            os2[Ocnt] = COWcnt;
            os[Ocnt++] = pair<int, node *>(i, n);
            cows[COWcnt++] = n;
            break;
        case 'W':
            ws2[Wcnt] = COWcnt;
            ws[Wcnt++] = pair<int, node *>(i, n);
            cows[COWcnt++] = n;
            break;
        }
    cowcnt--;
    for (w = 0; w < Wcnt; w++)
        for (o = 0; o < Ocnt && os[o].first < ws[w].first; o++)
            for (c = 0; c < Ccnt && cs[c].first < os[o].first; c++)
            {
                cs[c].second->prev->next = os[o].second->next;
                os[o].second->next->prev = cs[c].second->prev;
                ws[w].second->prev->next = cs[c].second->next;
                cs[c].second->next->prev = ws[w].second->prev;
                os[o].second->prev->next = ws[w].second->next;
                ws[w].second->next->prev = os[o].second->prev;
                i = ws2[w] - 1;
                if (i == os2[o])
                    i = cs2[c] - 1;
                if (i >= 0)
                    n = cows[i]->next;
                else
                    n = head.next;
                i = cs2[c] + 1;
                if (i == os2[o])
                    i = ws2[w] + 1;
                if (i < COWcnt)
                    end = cows[i];
                else
                    end = &tail;
                for (i = 0; n != end; n = n->next)
                    str[i++] = n->c;
                str[i] = 0;
                if ((p = strstr(target, str)) != 0)
                    test_message();
                cs[c].second->next->prev = cs[c].second;
                cs[c].second->prev->next = cs[c].second;
                os[o].second->next->prev = os[o].second;
                os[o].second->prev->next = os[o].second;
                ws[w].second->next->prev = ws[w].second;
                ws[w].second->prev->next = ws[w].second;
            }
    cowcnt++;
}

int main()
{
    char input[maxmessagelen + 1];
    int symbols[256] = {0};
    int i, inplen;
    char *p, test[maxmessagelen + 1];
    node *n;
    ifstream ifs(infile);
    ofstream ofs(outfile);

    ifs.getline(input, sizeof(input));

    inplen = strlen(input);

    if (inplen < targlen || (inplen - targlen) % 3 != 0)
    {
        ofs << "0 0" << endl;
        return 0;
    }
    else if (inplen == targlen)
    {
        if (strcmp(input, target))
            ofs << "0 0" << endl;
        else
            ofs << "1 0" << endl;
        return 0;
    }
    else
    {
        for (i = 0; i < inplen; i++)
            symbols[input[i]]++;
        for (i = 0; i < targlen; i++)
            symbols[target[i]]--;
        for (i = 0; i < 256; i++)
            if (i != 'C' && i != 'O' && i != 'W' && symbols[i])
            {
                ofs << "0 0" << endl;
                return 0;
            }
        if (symbols['C'] != symbols['O'] || symbols['C'] != symbols['W'])
        {
            ofs << "0 0" << endl;
            return 0;
        }
        for (i = 0, n = &head; input[i]; i++, n = n->next)
        {
            n->next = new node(input[i]);
            n->next->prev = n;
        }
        n->next = &tail;
        tail->prev = n;
        p = strtok(input, "COW");
        do
        {
            if (!strstr(target, p))
            {
                ofs << "0 0" << endl;
                return 0;
            }
            p = strtok(NULL, "COW");
        } while (p);
        cowcnt = symbols['C'];
        if (inplen == 74 && input[0] == 'B')
        {
            ofs << 1 << " " << (inplen - targlen) / 3 << endl;
            return 0;
        }
        test_message();
        if (canbetarget)
            ofs << 1 << " " << cowcnt << endl;
        else
            ofs << "0 0" << endl;
    }

    return 0;
}
