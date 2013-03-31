#include <stdio.h>
#include <string>

#define Mi 1000000007
#define N 51

using namespace std;

int F[2][3][3][N][N][N];

class ColorfulCupcakesDivTwo
{
public:
    int countArrangements(string s)
    {
        int C[3];
        C[0] = C[1] = C[2] = 0;
        for (int i = 0; i < s.length(); i++)
            C[s[i] - 'A']++;
        if (C[0])
            F[0][0][0][1][0][0] = 1;
        if (C[1])
            F[0][1][1][0][1][0] = 1;
        if (C[2])
            F[0][2][2][0][0][1] = 1;
        for (int cur_pos = 0; cur_pos + 1 < s.length(); cur_pos++)
        {
            memset(F[1 - cur_pos % 2], 0, sizeof(F[1 - cur_pos % 2]));
            for (int fst_col = 0; fst_col < 3; fst_col++)
                for (int cur_col = 0; cur_col < 3; cur_col++)
                    for (int cnt_0 = 0; cnt_0 <= C[0]; cnt_0++)
                        for (int cnt_1 = 0; cnt_1 <= C[1]; cnt_1++)
                            for (int cnt_2 = 0; cnt_2 <= C[2]; cnt_2++)
                                if (F[cur_pos % 2][fst_col][cur_col][cnt_0][cnt_1][cnt_2] != 0)
                                    for (int nxt_col = 0; nxt_col < 3; nxt_col++)
                                        if (nxt_col != cur_col)
                                        {
                                            F[1 - cur_pos % 2][fst_col][nxt_col][cnt_0 + (nxt_col == 0)][cnt_1 + (nxt_col == 1)][cnt_2 + (nxt_col == 2)] += F[cur_pos % 2][fst_col][cur_col][cnt_0][cnt_1][cnt_2];
                                            F[1 - cur_pos % 2][fst_col][nxt_col][cnt_0 + (nxt_col == 0)][cnt_1 + (nxt_col == 1)][cnt_2 + (nxt_col == 2)] %= Mi;
                                        }
        }
        int ans = 0;
        for (int fst_col = 0; fst_col < 3; fst_col++)
            for (int cur_col = 0; cur_col < 3; cur_col++)
                if (cur_col != fst_col)
                {
                    ans += F[(s.length() - 1) % 2][fst_col][cur_col][C[0]][C[1]][C[2]];
                    ans %= Mi;
                }
        return ans;
    }
};
