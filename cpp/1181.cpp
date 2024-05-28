#include <string.h>
#include <stdio.h>
int heap[40003];
int last = 0;
int dict_last = 0;
char dict[20000][50];
int dn[20000];
long long int cache[50] = {1};
long long int pow(int n)
{
    if (cache[n]!= 0)
    {
        return cache[n];
    }
    cache[n] = (pow(n-1)*31)%1234567891;
    return cache[n];
}
long long int my_hash(const char* text)
{
    long long int ans = 0;
    for (int i = 0; i < strlen(text); i ++)
    {
        ans += (text[i] - 'a' + 1) * pow(i);
    }
    return ans;
}
int is_right_bigger(int a,int b)
{
    int a_len = strlen(dict[a]);
    int b_len = strlen(dict[b]);
    if (a_len > b_len) return 0;
    if (a_len < b_len) return 1;
    for (int i = 0; i < a_len; i ++)
    {
        if (dict[a][i] > dict[b][i]) return 0;
        if (dict[a][i] < dict[b][i]) return 1;
    }
    return -1;
}
void what()
{
    for (int i = 0; i <= last; i ++)
        printf("%d ",heap[i]);
    printf("\n");
}
void what2()
{
    for (int i = 0; i <= dict_last; i ++)
        printf("%s ",dict[i]);
    printf("\n");
}
void what3()
{
    for (int i = 0; i <= dict_last; i ++)
        printf("%s ",dict[heap[i]]);
    printf("\n");
}
int del()
{
    int now = 1;
    int ans = heap[1];
    heap[1] = heap[last];
    heap[last] = 0;
    if (last >= 1)
        last--;
    while (now <= last/2)
    {
        int child = now * 2;
        // 왼쪽과 오른쪽 자식 중 더 작은 값을 가진 자식을 선택
        
        if (child < last && is_right_bigger(child, child+1))
            child++;
        // 왼쪽 노드가 0이 아니고 오른쪽 노드가 0일 때 왼쪽 노드와 대소비교
        else if (heap[child] != 0 && heap[child+1] == 0)
            child = now * 2;
        // 부모가 자식보다 작거나 같으면, 힙 조건 만족
        if (is_right_bigger(child, now) || heap[child] == 0)
            break;
        // 부모와 자식 교환
        unsigned int t = heap[now];
        heap[now] = heap[child];
        heap[child] = t;
        // now의 값을 증가시키기 전에 now가 last/2보다 작거나 같은지 확인
        if (now <= last/2)
            now = child;
        else
            break;
    }
    return ans;
}
void put(int a)
{
    last++;
    heap[last] = a;
    for (int i = last; i != 0; i/=2)
    {
        if (is_right_bigger(i, i/2))
        {
            int t = heap[i];
            heap[i] = heap[i/2];
            heap[i/2] = t;
        } else break;
    }
    
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i ++)
    {
        char a[50] = {0};
        scanf("%s",a);
        dn[dict_last] = my_hash(a);
        int p = 0;
        for (int j = 0; j < dict_last; j ++)
        {
            if (dn[dict_last] == dn[j])
            {
                p = 1;
                continue;
            }
        }
        if (p) continue;
        for (int j=0;a[j]!=0;j++)
        {
            dict[dict_last][j]=a[j];
        }
        put(dict_last);
        what2();
        what();
        what3();
        dict_last++;
    }
    for (int i = 0; i < dict_last;i++)
    {
        printf("%s\n",dict[del()]);
    }
}