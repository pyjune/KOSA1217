#include <stdio.h>
/*
5 6
1 2 1 3 3 2 2 5 5 4 3 4
*/
 
int adj[6][6];
int visited[6];
int V;
int E;
void dfs(int n);

int main(void) {
	scanf("%d %d", &V, &E);
	for(int i = 0; i < E; i++)
	{
		int n1, n2;
		scanf("%d %d", &n1, &n2);
		adj[n1][n2] = 1;
	}
	dfs(1);
	return 0;
}

void dfs(int n)
{
	visited[n] = 1;
	printf("%d\n", n);
	for(int i = 1; i<=V; i++)
	{
		if(adj[n][i]!=0 && visited[i]==0) // 인접하고, 미방문인 노드로 이동 
		{
			dfs(i);
		}
	}
}
