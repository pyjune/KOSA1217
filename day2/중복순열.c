#include <stdio.h>

int p[3];
int a[] = {1,2,3,4, 5};

void f(int n, int k);

int main(void) {
	//f(0, 3);
	f2(0, 3, 5); 
	return 0;
}

void f2(int n, int k, int m)
{
	if( n == k ) // 3자리 숫자가 완성된 경우 
	{
		for(int i = 0; i < k; i++)
			printf("%d ", p[i]);
		printf("\n");
	}
	else
	{
		for(int i = 0; i < m; i++)
		{
			p[n] = a[i];
			f2(n+1, k, m);
		}
	}
}

void f(int n, int k)
{
	if( n == k ) // 3자리 숫자가 완성된 경우 
	{
		for(int i = 0; i < k; i++)
			printf("%d ", p[i]);
		printf("\n");
	}
	else
	{
		for(int i = 0; i < k; i++)
		{
			p[n] = a[i];
			f(n+1, k);
		}
	}
}
