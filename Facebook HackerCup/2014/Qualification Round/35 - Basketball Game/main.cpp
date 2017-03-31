#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
#include <map>
#define _USE_MATH_DEFINES
#include <math.h>
#include <list>
#include <fstream>
#include <time.h>
#include <iomanip>
#include <queue>
#include <stack>
#include <complex>
#include <limits.h>
#include <cassert>
#include <chrono>
#include <regex>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <unordered_map>
#include <unordered_set>

using namespace std;
using namespace std::chrono;

class Human
{
private:
    string name;
    int shot_p;
    int height;
    int play_time;
    bool is_playing;
    int draft_id;

public:
    Human() : play_time(0), is_playing(false) {}
    static void sort_for_start(vector<Human> &);
    static vector<Human> get_team(const vector<Human> &, int, int);
    static void start_game(vector<Human> &, int);
    static void play_minute(vector<Human> &);
    static vector<Human> get_playing(const vector<Human> &);
    friend istream &operator>>(istream &in, Human &cur);
    friend ostream &operator<<(ostream &out, vector<Human> cur);
};

void Human::sort_for_start(vector<Human> &a)
{
    sort(a.begin(), a.end(), [](const Human &x, const Human &y) -> bool {
        return x.shot_p > y.shot_p || (x.shot_p == y.shot_p && x.height > y.height);
    });
    for (int i = 0; i < a.size(); ++i)
        a[i].draft_id = i;
}

vector<Human> Human::get_team(const vector<Human> &a, int team_id, int teams_n)
{
    team_id %= teams_n;
    vector<Human> res;
    for (int i = team_id; i < a.size(); i += teams_n)
        res.push_back(a[i]);
    return res;
}

void Human::play_minute(vector<Human> &a)
{
    for (int i = 0; i < a.size(); ++i)
        if (a[i].is_playing)
            ++a[i].play_time;
    auto better_leave = [](const Human &x, const Human &y) {
        return y.is_playing == true && (x.is_playing == false ||
                                        (y.play_time > x.play_time || (y.play_time == x.play_time && y.draft_id > x.draft_id)));
    };
    auto better_enter = [](const Human &x, const Human &y) {
        return y.is_playing == false && (x.is_playing == true ||
                                         (y.play_time < x.play_time || (y.play_time == x.play_time && y.draft_id < x.draft_id)));
    };
    int leave_id = 0, enter_id = 0;
    for (int i = 0; i < a.size(); ++i)
    {
        if (better_leave(a[leave_id], a[i]))
            leave_id = i;
        if (better_enter(a[enter_id], a[i]))
            enter_id = i;
    }
    if (a[leave_id].is_playing && !a[enter_id].is_playing)
    {
        a[leave_id].is_playing = false;
        a[enter_id].is_playing = true;
    }
}

void Human::start_game(vector<Human> &a, int n_play)
{
    for (int i = 0; i < a.size() && i < n_play; ++i)
        a[i].is_playing = true;
}

vector<Human> Human::get_playing(const vector<Human> &a)
{
    vector<Human> res;
    for (Human i : a)
        if (i.is_playing)
            res.push_back(i);
    return res;
}

istream &operator>>(istream &in, Human &cur)
{
    in >> cur.name >> cur.shot_p >> cur.height;
    return in;
}

ostream &operator<<(ostream &out, vector<Human> cur)
{
    sort(cur.begin(), cur.end(), [](const Human &x, const Human &y) {
        return x.name < y.name;
    });
    for (Human &i : cur)
        out << " " << i.name;
    return out;
}
//#define ONLINE_JUDGE
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T;
    cin >> T;
    for (int _t = 0; _t < T; ++_t)
    {
        int n, m, p;
        cin >> n >> m >> p;
        vector<Human> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        Human::sort_for_start(a);
        vector<Human> first = Human::get_team(a, 0, 2);
        vector<Human> second = Human::get_team(a, 1, 2);
        Human::start_game(first, p);
        Human::start_game(second, p);
        for (int i = 0; i < m; ++i)
        {
            Human::play_minute(first);
            Human::play_minute(second);
        }
        a = Human::get_playing(first);
        vector<Human> b = Human::get_playing(second);
        a.insert(a.end(), b.begin(), b.end());
        cout << "Case #" << _t + 1 << ":" << a << endl;
    }
    return 0;
}
