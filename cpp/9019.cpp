#include <stdio.h>
int num;
//4진 트리 인생 어캐만듬 ㅇㅅㅇ;;
short action[2000];
short nums[2000];
short print[2000];
short D = 1;
short S = 2;
short L = 3;
short R = 0;
int D_(int n) {return (n*2)%10000;}
int S_(int n) {return (n+9999)%10000;}
int L_(int n)
{
    int k = 0;
    k += n * 10;
    k += n / 1000;
    return k % 10000;
}
int R_(int n)
{
    int k = 0;
    k += (n % 10)*1000;
    k += n/10;
    return k;
}
void find(short from)
{
    short now = 0, lookat=1;
    int first_of_line = 1;
    short to;
    scanf("%hd",&to);
    nums[0] = from;
    for (int i = 0; i < 2000; i ++)
    {
    	printf("%d\n",lookat);
        if (lookat == 4 * first_of_line + 1)
        {
            first_of_line = first_of_line * 4 + 1;
        }
        int pure = lookat - first_of_line;
        if (pure%4 == D)
        {
            nums[lookat] = D_(nums[lookat]);
        }
        else if (pure%4 == S)
        {
            nums[lookat] = S_(nums[lookat]);
        }
        else if (pure%4 == L)
        {
            nums[lookat] = L_(nums[lookat]);
        }
        else
        {
            nums[lookat] = R_(nums[lookat]);
        }
        action[lookat] = pure % 4;
        if (nums[lookat] == to) break;
        lookat ++;
    }
    int i = 0;
    while (1)
    {
        print[i] = action[lookat];
        int next = (lookat - first_of_line) / 4;
        first_of_line = (first_of_line-1)/4;
        next += first_of_line;
        lookat = next;
        if (nums[lookat] == from) break;
    }
    for (int j = 0; j < i;j++)
    {
        if (print[j] == 0) printf("R");
        else if (print[j] == 1) printf("D");
        else if (print[j] == 2) printf("S");
        else if (print[j] == 3) printf("L");
    }
    printf("\n");
}
int main()
{
    int t;
    scanf("%d",&t);
    /*
    for (int i = 0; i < t; i ++)
    {
        short k;
        scanf("%hd",&k);
        find(k);
    }
    */
    find(t);
}