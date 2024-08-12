#include <stdio.h>
int min,max,j, n, i, a, b, c;
short nums[100001][3];
short difs[100001][3];
// 뭐야 이거 어카지
int main()
{
    int min_now = 0;
    int max_now = 0;
    int max_now_going = 1; //-1 0 1로 하면 햇갈ㄹ게지? 0 1 2
    int min_now_going = 1;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%hd", &nums[i][j]);
        }
        if (i==1) continue;
        int lookat = i-1;
        difs[lookat][0] = nums[lookat][0]-nums[lookat][1]+
        //idea 1 <- 연속성 보장을 못함
        //3진 트리<- 뭔 도른짓이지 이건...
        //최댓값만 두번 돌면 최소도 구해짐. 따라서 최대/최소만 구할줄 알면 됨
        /*
        100 
        100
        100
        100
        100
        009
        0 0 0 0 1 2//idea 1 맞을지도?
        */
    }

    return 0;

} // 대체 이거 왜 그 밑줄 안뜸
