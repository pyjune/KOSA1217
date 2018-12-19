#include <stdio.h>

int visited[100001];
int q[100001];
int bfs2(int n, int k);

int main(void) {
	int N, K;
	scanf("%d %d", &N, &K);
	printf("%d\n", bfs2(N, K));
	
	return 0;
}

int bfs2(int n, int k)
{
	int front = -1;
	int rear = -1;
	// 시작점 인큐, 방문표시
	q[++rear] = n; 
	visited[n] = 1;
	while( front != rear ) // 큐가 비어있지 않으면 반복 
	{
		n = q[++front]; // 처리할 노드 디큐
		if(n==k)
			return (visited[k] - 1);
			
		// n에 인접하고 미방문이면..
		if(n - 1 >= 0 && visited[n - 1] == 0)
		{
			q[++rear] = n - 1;
			visited[n - 1] = visited[n] + 1;
		}
		if(n + 1 <= 100000 && visited[n + 1] == 0)
		{
			q[++rear] = n + 1;
			visited[n + 1] = visited[n] + 1;
		}
		if(n * 2 <= 100000 && visited[n * 2] == 0)
		{
			q[++rear] = n * 2;
			visited[n * 2 ] = visited[n] + 1;
		}
		
	}
	return 0;
}






