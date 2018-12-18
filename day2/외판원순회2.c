#include <stdio.h>

int W[10][10];
int p[10];
int used[10];
int minV = 0x7fffffff;

void f(int n, int k, int s);

int main(void) 
{
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			scanf("%d", &W[i][j]);
		}
	}
	used[0] = 1;
	p[0] = 0;
	f(1, N, 0);
	printf("%d\n", minV);
	return 0;
}

void f(int n, int k, int s)
{
	if(n == k)
	{
		if(W[p[k-1]][0]!=0 && minV > (s+W[p[k-1]][0]))
			minV = s+W[p[k-1]][0];
	}
	else if(s>=minV)
	{
		return;
	}
	else
	{
		for(int i = 0; i < k; i++)
		{
			if(used[i] == 0 && W[p[n-1]][i] != 0)
			{
				used[i] = 1;
				p[n] = i;
				f(n+1, k, s+W[p[n-1]][i]);
				used[i] = 0;
			}
		}
	}
}
