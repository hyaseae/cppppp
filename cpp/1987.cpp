// Online C++ compiler to run C++ program online
#include <stdio.h>
#include <stack>
int R,C;
int area[20][21];

using namespace std;

typedef struct pasdfasdfsda {
    int x;
    int y;
    int depth;
    int gone_somewhere = 0;
} point;

typedef struct asdfase {
    int x;
    int y;
} laziness;

stack<point> s;

laziness lazy[4] = {{-1,0},{1,0},{0,-1},{0,1}};


inline int inside(int x, int y)
{
    if (x >= C) return 0;
    if (x < 0) return 0;
    if (y >= R) return 0;
    if (y < 0) return 0;
    return 1;
}

int main()
{
    scanf("%d %d",&R,&C);
    for (int i = 0 ; i < R; i ++)
    {
        for (int j = -1; j < C; j ++)
        {
            char temp;
            scanf("%c",&temp);
            area[i][j] = (int) temp;
        }

    }
    s.push({0,0,1});
    
    int depth_max = 0;

    while (!s.empty())
    {
        point now = s.top();
        s.pop();
        int now_char = area[now.y][now.x];
        now_char -= 'A';
        now.gone_somewhere = now.gone_somewhere | (1<<now_char);
        
        for (int i = 0 ; i < 4; i ++)
        {
            laziness a = lazy[i];
            if (inside(now.x + a.x, now.y+a.y))
            {
                int temp = area[now.y+a.y][now.x+a.x] - 'A';
                if ((now.gone_somewhere & (1<<temp))<=0)
                {
                    s.push({now.x+a.x,now.y+a.y,now.depth+1,now.gone_somewhere});
                }
            }
        }
        if (now.depth > depth_max)
        {
            depth_max = now.depth;
        }
    }
    printf("%d\n",depth_max);

}