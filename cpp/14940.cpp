#include <queue>
#include <stdio.h>
int n, m;
short way[1001][1001];
typedef std::pair<int, int> cord;
std::queue<cord> Q;
cord start = std::make_pair(0, 0);
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%hd", &way[i][j]);
            if (way[i][j] == 2)
            {
                start = std::make_pair(i, j);
                Q.push(start);
            }
        }
    }
    while (Q.empty() != 0)
    {
        cord now = Q.front();
        Q.pop();
        printf("%d %d\n", now.first, now.second);
        int place[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (int i = 0; i < 4; i++)
        {
            if (way[place[i][0] + now.first][place[i][0] + now.second] == 1)
            {
                
            }
        }
    }
}