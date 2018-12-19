#include <stdio.h>

int maze[100][100];

int find(int r, int c);
int N;
int main(void) 
{
	int T;
	int sr, sc;
	int d;
	//freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for(int tc = 1; tc <= T; tc++)
	{

		scanf("%d", &N);
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				scanf("%1d", &d);
				maze[i][j] = d;
				if(d == 2) // 시작 좌표 
				{
					sr = i;
					sc = j;
				}
			}
		}
		printf("#%d %d\n", tc, find(sr, sc));	
	}	
	return 0;
}

int find(int r, int c)
{
	int dr[] = {0, 1, 0, -1};
	int dc[] = {1, 0, -1, 0};
	 
	if(maze[r][c] == 3)
	{
		return 1;
	}
	else
	{
		maze[r][c] = 1;
		// 인접이고 미방문인 칸으로 이동...
		for(int i = 0; i < 4; i++)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];
			if(maze[nr][nc] != 1) // 벽이 아니면 인접.. 
				if(find(nr, nc) == 1)
					return 1; 
		}
		return 0;	 
	}
}
