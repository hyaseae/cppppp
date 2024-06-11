#include <stdio.h>
const int INF = 2147483647;
int graph[10][10];
int v,e;
bool visited[10];
int d[10];

void show_d()
{
	for (int i =1; i <= v; i++)
	{
		printf("%d ",d[i]);
	}
	printf("\n");
}
int find_next(int line)
{
	int min = INF;
	int index = -1;
	for (int i = 1; i <= v; i ++)
	{
		if (i == line) continue;
		if (visited[i]) continue;
		if (min > d[i])
		{
			min = d[i];
			index = i;
			visited[i] = 1;
		}
	}
	return index;
}


void init(int line)
{
	for (int i = 1; i <= v; i ++)
	{
		if (i == line) continue;
		d[i] = INF;
	}
}

void show()
{
	for (int i =1; i <= v; i++)
	{
		printf("%d:",i);
		for (int j = 1; j <=v;j++)
			printf("%d ",graph[i][j]);
		printf("\n");
	}
}
int main()
{
	scanf("%d %d",&v,&e);
	for (int i = 1; i <= v; i ++)
	{
		int from,to;
		scanf("%d %d",&from,&to);
		graph[from][to] = graph[to][from] = 1;
	}
	int from,to;
	scanf("%d %d",&from,&to);
	init(1);
	show();
	int now = from;
	for (int asdf = 1; asdf < 10; asdf ++)
	{
		//현재 줄 비교
		for (int i = 1; i <= v; i ++)
		{ 
			if (i == now) continue;
			if (graph[now][i] != 0)
			{
				if (d[now] + graph[now][i] < d[i])
				{
					d[i] = d[now] + graph[now][i];
				}
			}
		}
		now = find_next(now);
		show_d();
		if (now == -1) break;
	}
}
/*
6 6
1 2
1 5
2 6
3 5
4 6
5 6
1 4


*/
