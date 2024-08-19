#include <stdio.h>
// 최대 힙
unsigned int heap[200002];
int last = 0;
void what()
{
    for (int i = 0; i <= last; i++)
        printf("%d ", heap[i]);
    printf("\n");
}
void del()
{
    int now = 1;
    printf("%d\n", heap[1]);
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
        unsigned int t = heap[now];
        heap[now] = heap[child];
        heap[child] = t;
        // now의 값을 증가시키기 전에 now가 last/2보다 작거나 같은지 확인
        if (now <= last / 2)
            now = child;
        else
            break;
    }
}
void put(unsigned int a)
{
    last++;
    heap[last] = a;
    for (int i = last; i != 0; i /= 2)
    {
        if (heap[i] < heap[i / 2])
        {
            unsigned int t = heap[i];
            heap[i] = heap[i / 2];
            heap[i / 2] = t;
        }
        else
            break;
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        unsigned int a;
        scanf("%u", &a);
        if (a == 0)
            del();
        else
            put(a);
    }
}
/*
8 14 23 51 13 2 6 7 5 99 0 75 90
*/