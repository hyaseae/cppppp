#include <stdio.h>
#include <queue>
#include <utility>
int n,m;
short way[1000][1000];
typedef std::pair<int,int> cord;
std::queue<cord> Q;
cord start = std::make_pair(0, 0);
int main()
{
    scanf("%d %d",&n,&m);
    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < m; j ++)
        {
            scanf("%hd",&way[i][j]);
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
        printf("%d %d\n",now.first,now.second);
        
    }
}