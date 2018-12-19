#include <stdio.h>

/*
5 6
1 2 1 3 3 2 2 5 5 4 3 4
*/
int adj[6][6];
int visited[6];
int V;
int E;

void bfs(int n);

int main(void) {
	scanf("%d %d", &V, &E);
	for(int i = 0; i < E; i++)
	{
		int n1, n2;
		scanf("%d %d", &n1, &n2);
		adj[n1][n2] = 1;
	}
	bfs(1);
	return 0;
}

void bfs(int n)
{
	int q[6];
	int front = -1;
	int rear = -1;
	// 시작점 인큐, 방문표시
	q[++rear] = n; 
	visited[n] = 1;
	while( front != rear ) // 큐가 비어있지 않으면 반복 
	{
		n = q[++front]; // 처리할 노드 디큐
		printf("%d\n", n);
		for(int i = 1; i <= V; i++)
		{
			if(adj[n][i] != 0 && visited[i] == 0) // n에 인접이고, 미방문이면..
			{
				q[++rear] = i;
				visited[i] = visited[n] + 1;
			} 
		}
		
	}
}
