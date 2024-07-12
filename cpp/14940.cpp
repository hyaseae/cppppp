#include <queue>
#include <stdio.h>
#include <utility>
int n, m;
short way[1001][1001];
int ans[1001][1001];
typedef std::pair<int, int> cord;
std::queue<cord> Q;
cord start = std::make_pair(0, 0);
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i<n; i++){
        for ( int j =0; j < m; j++){
            ans[i][j]=-1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%hd", &way[i][j]);
            if (way[i][j] == 2)
            {
                start = std::make_pair(i, j);
                Q.push(start);
                ans[start.first][start.second] = 0;
            }
            if (way[i][j]==0)
            {
                ans[i][j]=0;
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
            int a = place[i][0]+now.first;
            int b = place[i][1]+now.second;
            if (way[a][b] == 1 && ans[a][b]!=-1)
            {
                ans[a][b] = ans[now.first][now.second]+1;
                Q.push(std::make_pair(a, b));

            }
        }
    }
}