#include <stdio.h>

int maze[100][100];

int N;
int cnt;
void find(int r, int c);

int minV;
void find2(int r, int c, int e);

int q[10000];
int visited[100][100];
int find3(int r, int c);

int main(void) 
{
	int T;
	int sr, sc;
	int d;
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for(int tc = 1; tc <= T; tc++)
	{
		//cnt = 0;
		minV = 0x7fffffff;
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
		//find(sr, sc);
		//printf("#%d %d\n", tc, cnt);
//		find2(sr, sc, 0);
//		if( minV == 0x7fffffff)
//			minV = 1;
//		printf("#%d %d\n", tc, minV-1);
		printf("#%d %d\n", tc, find3(sr, sc));
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				visited[i][j] = 0;
			}
		}
		
	}
	return 0;
}

int find3(int r, int c)
{
	int dr[] = {0, 1, 0, -1};
	int dc[] = {1, 0, -1, 0};
	int front = -1;
	int rear = -1;
	q[++rear] = r;
	q[++rear] = c;
	visited[r][c] = 1;
	while(front != rear)
	{
		r = q[++front];
		c = q[++front];
		if(maze[r][c] == 3)
			return (visited[r][c] - 2);
		for(int i = 0; i < 4; i++)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];
			if(maze[nr][nc] != 1 && visited[nr][nc] == 0)
			{
				q[++rear] = nr;
				q[++rear] = nc;
				visited[nr][nc] = visited[r][c] + 1;	
			}
		}
	}
	return 0;
}

void find2(int r, int c, int e)
{
	int dr[] = {0, 1, 0, -1};
	int dc[] = {1, 0, -1, 0};
	
	if(maze[r][c] == 3)
	{
		if(minV > e)
			minV  = e;
	}
	else
	{
		maze[r][c] = 1;
		for(int i = 0; i < 4; i++)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];
			if(maze[nr][nc] != 1)
				find2(nr, nc, e+1);
		}
		maze[r][c] = 0;
	}
}

void find(int r, int c)
{
	int dr[] = {0, 1, 0, -1};
	int dc[] = {1, 0, -1, 0};
	
	if(maze[r][c] == 3)
	{
		cnt++;
	}
	else
	{
		maze[r][c] = 1;
		for(int i = 0; i < 4; i++)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];
			if(maze[nr][nc] != 1)
				find(nr, nc);
		}
		maze[r][c] = 0;
	}
}
