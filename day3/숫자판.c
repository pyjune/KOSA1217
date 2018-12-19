#include <stdio.h>

int num[10][10];
int used[10][10];
int p[10];
int N;
int M;

int find(void);
int dfs(int r, int c, int k);

int main(void) 
{
	int T;
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for(int tc = 1; tc <= T; tc++)
	{
		scanf("%d", &N);
		for(int i = 0; i < N; i++)
			scanf("%d", &p[i]);
		scanf("%d", &M);
		for(int i = 0; i < M; i++)
		{
			for(int j = 0; j < M; j++)
			{
				scanf("%d", &num[i][j]);
			}
		}
		printf("#%d %d\n", tc, find());
	}
	
	return 0;
}

int find(void)
{
	for(int i = 0; i < M; i++)
	{
		for(int j = 0; j < M; j++)
		{
			if(num[i][j] == p[0])
			{
				if(dfs(i, j, 0) == 1)
					return 1;
			}
		}
	}
	return 0;
}

int dfs(int r, int c, int k)
{
	int dr[] = {0, 1, 0, -1};
	int dc[] = {1, 0, -1, 0};
	
	if(k == N) // 이미 모든 숫자를 찾은 경우... 
	{
		return 1;
	}
	else if( num[r][c] != p[k]) // 찾는 숫자가 아닌 경우 
	{
		return 0;
	}
	else
	{
		used[r][c] = 1;
		for(int i = 0; i < 4; i++)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];
			if(nr>=0 && nr<M && nc>=0 && nc<M)
			{
				if(used[nr][nc] == 0)
				{
					if(dfs(nr, nc, k+1)==1)
					{
						used[r][c] = 0; // 별도의 used[][] 초기화 필요 없도록.. 
						return 1;
					}
				}
			}
		}
		used[r][c] = 0;
		return 0;
	}
}
