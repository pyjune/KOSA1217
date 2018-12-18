#include <stdio.h>

int a[] = {1,2,3, 4, 5};
int used[5];
int p[3];

int f(int n, int k, int m); // n현재인덱스, k는 순열의 길이, m 사용할 수 있는 숫자 개수 

int main(void) {
	
	f(0, 3, 5); 
	
	return 0;
}
int f(int n, int k, int m)
{
	if(n == k)
	{
		for(int i = 0; i < k; i++)
			printf("%d ", p[i]);
		printf("\n");
	}
	else
	{
		for(int i = 0; i < m; i++)
		{
			if(used[i] == 0)
			{
				used[i] = 1;
				p[n] = a[i];
				f(n+1, k, m);
				used[i] = 0;
			}
		}
		
		
	}
}
