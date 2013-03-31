#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstdlib>
#include <limits.h>
#include <algorithm>
#include <iterator>

using namespace std;

struct Tree
{
    int data, id;
    vector<Tree *> sons;
};

bool equals(Tree *where, Tree *what)
{
    if (where->data != what->data || where->sons.size() != what->sons.size())
        return false;
    for (int i = 0; i < where->sons.size(); ++i)
        if (!equals(where->sons[i], what->sons[i]))
            return false;
    return true;
}

void search(Tree *where, Tree *what)
{
    if (equals(where, what))
        cout << where->id << endl;
    for (int i = 0; i < where->sons.size(); ++i)
        search(where->sons[i], what);
}

void read_tree(vector<Tree *> &a)
{
    int n;
    cin >> n;
    a.assign(n, nullptr);
    for (int i = 0; i < n; ++i)
        a[i] = new Tree;
    for (int i = 0; i < n; ++i)
    {
        a[i]->id = i;
        cin >> a[i]->data;
        int p;
        cin >> p;
        if (p != -1)
            a[p]->sons.push_back(a[i]);
    }
}

vector<Tree *> fst, snd;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    read_tree(fst);
    read_tree(snd);
    search(fst[0], snd[0]);
    return 0;
}
