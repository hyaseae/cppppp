#include <sched.h>
#include <stdio.h>

typedef struct cords {
    int x,y;
} cord;
int pow2(int a)
{
    return a*a;
}
int get_r(cord p1, cord p2)
{
    return pow2(p1.x-p2.x)+pow2(p1.y-p2.y);
}
int in_it(cord p, cord c, short r)
{
    if (get_r(p, c) > pow2(r))
    {
        return 0;
    }
    return 1;
}
int main()
{
    int t;
    scanf("%d",&t);
    for (int i = 0 ; i< t; i ++)
    {
        int x1,y1,x2,y2,n,cnt = 0;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        scanf("%d",&n);
        cord start = {x1,y1};
        cord end = {x2,y2};
        for (int j = 0; j <n; j++)
        {
            int c1,c2,r;
            scanf("%d %d %d",&c1,&c2,&r);
            cord point = {c1,c2};
            int s_init = in_it(start, point, r);
            int e_init = in_it(end, point, r);
            if (s_init == 0 && e_init ==1)
            {
                cnt ++;
            }
            else if (e_init == 0 && s_init == 1)
            {
                cnt++;
            }
        }
        printf("%d\n",cnt);
        
    }


    return 0;
}