#include <stdio.h>
typedef long long int lld;
lld heap[200002];
typedef struct five_elements
{
    int num;
    int p1;
    int p2;
    int c1;
    int c2;
} item;
item a = {1, 1, 1, 1, 1};

// 아이디어:이중 힙...?
//  정렬만 해도 답이 나온다고? 이거 완전 럭키비키잖아~ <-아님 <- 시간초과
/*
1

1
5

1
3
5

1
3
5

1
3
5 7

1
3 5
7

1
3 5
7 4
않이 그니까 미는 것도 시간이 든다니까 에반디;;
거꾸로 힙 쌓기?


1

1 3

1 3 4

1
3 4

1
3 4 7

1
3 4
7







*/
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
void del_min()
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
void insert_at_place(lld a, int where)
{
}
void del_max()
{
}
void put(lld a)
{
}
int get_max()
{
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
                if (last <= 0)
                    continue;
                if (q == -1)
                {
                    del_min();
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

        printf("%lld %lld\n", heap[1] > 0 ? heap[1] : heap[1] + 1, heap[max_] > 0 ? heap[max_] : heap[max_] + 1);
    }
}