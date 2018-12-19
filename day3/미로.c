#include <stdio.h>

int maze[100][100];

int find(int r, int c); // dfs 재귀 
int find2(int r, int c); // dfs 반복
int stack[10000];
int top;

int q[10000];
int visited[100][100];
int find3(int r, int c); // bfs 

int N;
int main(void) 
{
	int T;
	int sr, sc;
	int d;
	freopen("input.txt", "r", stdin);
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
		printf("#%d %d\n", tc, find3(sr, sc));
		//printf("#%d %d\n", tc, find2(sr, sc));
		//printf("#%d %d\n", tc, find(sr, sc));
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
			return 1 ;
		for(int i = 0; i < 4; i++)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];
			if((maze[nr][nc] != 1) && (visited[nr][nc] == 0))
			{			
				q[++rear] = nr;
				q[++rear] = nc;
				visited[nr][nc] = visited[r][c] + 1;
			}
		}
	}
	return 0;
}

int find2(int r, int c)
{
	int dr[] = {0, 1, 0, -1};
	int dc[] = {1, 0, -1, 0};
	
	top = -1;
	stack[++top] = r; // 시작점 push 
	stack[++top] = c;
	maze[r][c] = 1;  // 방문 표시
	while(top != -1)
	{
		c = stack[top--];
		r = stack[top--];
		/*
		if(maze[r][c] == 3) // visited[][]를 별도로 사용하는 경우.. 
			return 1;
		*/
		for(int i = 0; i < 4; i++)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];
			if(maze[nr][nc] != 1) // 벽이 아니면 인접..
			{
				if(maze[nr][nc] == 3)// visited[][]를 만들지 않는 경우... 
					return 1;
				stack[++top] = nr;
				stack[++top] = nc;
				maze[nr][nc] = 1;
			}
		}
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
