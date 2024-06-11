#include <stdio.h>
int d[100000];
int n;

int big(int a, int b)
{
	return a>b?a:b;
}
int small(int a, int b)
{
	return a<b?a:b;
}
void show()
{
	for (int i = 0 ; i < n ; i ++)
	{
		printf("%d ",d[i]);
	}
	printf("\n");
}
void swap(int a, int b)
{
	int t = d[a];
	d[a] = d[b];
	d[b] = t;
}

void Qsort(int from,int to)
{
	if (to - from <= 1) return;
	int a=0,b=0,c=0;
	int pivot = 0;
	int pivot_index = 0;
	a = d[from];
	b = d[to];
	c = d[(to-from)/2 + from];
	if (a>small(b,c)&& big(b,c)>a) // a 중앙 
	{
		;
	}
	else if (b>small(a,c)&& big(a,c)>b) // b 중앙 
	{
		swap(from,to);
	}
	else {
		swap((to-from)/2 + from,from);
	}
	//c 중앙
	pivot = d[from];
	int low = from+1;
	int high = to;
	pivot_index = from;
	int out = 0;
	while(out!=0)
	{
		while (1)
		{
			if (d[low] > pivot)
			{
				break;
			}
			if (low > high)
			break;
			low ++;
		}
		//low 찾음 
		while (1)
		{
			if (d[high] < pivot)
			{
				break;
			}
			if (low > high)
			break;
			high --;
		}
		if (low > high)
			break;
		
		swap(low,high);
	}
	swap(high,pivot_index);
	//왼 작 오 큼 
	
	Qsort(from,pivot_index);
    Qsort(pivot_index+1, to);
	
	return;
}


int main()
{
	
	scanf("%d",&n);
	for (int i = 0 ; i < n ; i ++)
	{
		scanf("%d",&d[i]);
	}
	Qsort(0,n);
	printf("r:");
	show();
}
//  14 10 6 3 9 5 7 8 4