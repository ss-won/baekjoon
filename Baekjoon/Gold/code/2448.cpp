#include <iostream>
#include <algorithm>
#include <functional>
#define MAX 3072
using namespace std;
int n;
char star[MAX][MAX * 2];
void drawstar(int x, int y, int n)
{
    if (n == 3)
    {
        for (int i = 0; i < 3; i++)
        {
            if (i == 0)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (j == 2)
                        star[x + i][y + j] = '*';
                    else
                        star[x + i][y + j] = ' ';
                }
            }
            else if (i == 1)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (j % 2 == 1)
                        star[x + i][y + j] = '*';
                    else
                        star[x + i][y + j] = ' ';
                }
            }
            else if (i == 2)
            {
                for (int j = 0; j < 5; j++)
                {
                    star[x + i][y + j] = '*';
                }
            }
        }
    }
    else
    {
        drawstar(x, y + (n / 2), n / 2);
        drawstar(x + (n / 2), y, n / 2);
        drawstar(x + (n / 2), y + n, n / 2);
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        fill(&star[i][0], &star[i][n * 2 - 1] + 1, ' ');
    }
    drawstar(0, 0, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n * 2 - 1; j++)
        {
            cout << star[i][j];
        }
        cout << "\n";
    }
    return 0;
}
