#include <algorithm>
#include <stdio.h>
typedef long long int lld;
lld heap[200002];
// 정렬만 해도 답이 나온다고? 이거 완전 럭키비키잖아~ <-아님 <- 시간초과
int last = 0, t, q, n, f, b, i, j;
char c;
void what()
{
    for (int i = 1; i <= last; i++)
        printf("%lld ", heap[i]);
    printf("\n");
}
void swap_heap(int a, int b)
{  
    lld t = heap[a];
    heap[a] = heap[b];
    heap[b] = t;
}
void del()
{
    int now = 1;
    heap[1] = heap[last];
    heap[last] = 0;
    if (last >= 1)
        last--;
    while (now <= last / 2)
    {
        int child = now * 2;
        // 왼쪽과 오른쪽 자식 중 더 작은 값을 가진 자식을 선택
        if (child < last && heap[child] > heap[child + 1])
            child++;
        // 왼쪽 노드가 0이 아니고 오른쪽 노드가 0일 때 왼쪽 노드와 대소비교
        else if (heap[child] != 0 && heap[child + 1] == 0)
            child = now * 2;
        // 부모가 자식보다 작거나 같으면, 힙 조건 만족
        if (heap[now] <= heap[child] || heap[child] == 0)
            break;
        // 부모와 자식 교환
        lld t = heap[now];
        heap[now] = heap[child];
        heap[child] = t;
        // now의 값을 증가시키기 전에 now가 last/2보다 작거나 같은지 확인
        if (now <= last / 2)
            now = child;
        else
            break;
    }
}
int get_max()
{
    lld max = -1 * (1l << 32);
    int max_index = -1;
    for (int k = last / 2 + 1; k <= last; k++)
    {
        if (max < heap[k])
        {
            max_index = k;
            max = heap[k];
        }
    }
    return max_index;
}
void insert_at_place(lld a,int where)
{
    heap[where] = a;
    for (int i = last; i != 0; i /= 2)
    {
        if (heap[i] < heap[i / 2])
        {
            lld t = heap[i];
            heap[i] = heap[i / 2];
            heap[i / 2] = t;
        }
        else
            break;
    }
}
void del_max()
{
    int max_index;
    max_index = get_max();
    swap_heap(last, max_index);
    insert_at_place(heap[max_index], max_index);
    heap[last] = 0;
    last--;
}
void put(lld a)
{
    last++;

    heap[last] = a > 0 ? a : a - 1;
    for (int i = last; i > 1; i /= 2)
    {

        if (heap[i] < heap[i / 2])
        {
            lld t = heap[i];
            heap[i] = heap[i / 2];
            heap[i / 2] = t;
        }
        else
            break;
    }
}
int main()
{
    scanf("%d", &t);
    for (i = 0; i < t; i++)
    {
        scanf("%d", &n);
        for (j = 0; j < n; j++)
        {
            scanf(" %c %d", &c, &q);
            if (c == 'I')
            {
                put(q);
            }
            else if (c == 'D')
            {
                if (last <= 0) continue;
                if (q == -1)
                {
                    del();
                }
                else if (q == 1)
                {
                    del_max();
                }
            }
        }
        if (last <= 0)
        {
            printf("EMPTY\n");
            continue;
        }

        int max_ = get_max();
        printf("%lld %lld\n",heap[1] > 0 ? heap[1] : heap[1] + 1,heap[max_] > 0 ? heap[max_] : heap[max_]+1);
    }
}