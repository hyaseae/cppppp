#include <stdio.h>
//나는 이 코드가 시간 초과를 받을 것을 알고 있지만, 시간이 부족해 더 나은 코드를 적지 않겠다.
char name[500000][20];
int val[500000];
int prime = 100000007;
long long int cache[20] = {1};
char p[20];
int ret[500000];
int cnt;
int pow(int n)
{
    if (cache[n]!= 0)
    {
        return (int)cache[n];
    }
    cache[n] = (pow(n-1)*31)%prime;
    return (int) cache[n];
}
int hashing(char* c)
{
    long long int ans = 0;
    for (int i = 0; c[i] != '\0'; i ++)
    {
        int k =((c[i] - 'a' + 1) * pow(i)); 
        ans += k;
        ans %= prime;
        //printf("%lld %d %c\n",ans,k,c[i]);
    }
    return (int) ans;
}
void put_name(char* p1,int index)
{
    for (int i = 0; p1[i] != '\0'; i++)
    {
        name[index][i] = p1[i];
    }
    return;
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i = 0; i < n; i ++)
    {
        scanf("%s",p);
        put_name(p, i);
        val[i] = hashing(p);
    }
    for (int i = 0; i < m; i ++)
    {
        scanf("%s",p);
        int hmm = hashing(p);
        for (int j = 0; j < n; j ++)
        {
            if (val[j] == hmm)
            {
                ret[cnt] = j;
                cnt ++;
            }
        }
    }
    printf("%d\n",cnt);
    for (int i = 0; i < cnt; i ++)
    {
        printf("%s\n",name[ret[i]]);
    }
}