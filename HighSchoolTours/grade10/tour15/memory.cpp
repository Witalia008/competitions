#include "grader.h"
#include "memory.h"

void play()
{
    char a[51];
    bool used[51];
    for (int i = 1; i <= 50; i++)
        used[i] = false;
    for (int i = 1; i <= 25; i++)
    {
        a[2 * i - 1] = faceup(2 * i - 1);
        a[2 * i] = faceup(2 * i);
        if (a[2 * i] == a[2 * i - 1])
        {
            used[2 * i] = true;
            used[2 * i - 1] = true;
        }
    }
    for (int i = 1; i <= 50; i++)
        if (!used[i])
        {
            int j = i + 1;
            while (a[j] != a[i])
                j++;
            faceup(i);
            faceup(j);
            used[j] = true;
            used[i] = true;
        }
}
