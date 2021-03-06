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
void dfs2(int n);
int dfs3(int n, int k);
int dfs4(int n, int k);
 
int main(void) {
	scanf("%d %d", &V, &E);
	for(int i = 0; i < E; i++)
	{
		int n1, n2;
		scanf("%d %d", &n1, &n2);
		adj[n1][n2] = 1;
	}
	//dfs(1); // 재귀
	//dfs2(1); // 반복
	//printf("%d\n", dfs3(3, 5));
	printf("%d\n", dfs4(3, 5)); 
	return 0;
}
void dfs2(int n)
{
	int top = -1;
	int stack[6];
	stack[++top] = n; // push()
	visited[n] = 1;
	while(top!=-1) // 스택이 비어있지 않으면 
	{
		n = stack[top--]; // pop()
		printf("%d\n", n);
		for(int i = 1; i<=V; i++)
		{
			if(adj[n][i]!=0 && visited[i]==0) // 인접하고, 미방문인 노드 
			{
				stack[++top] = i;
				visited[i] = 1;
			}
		}
	}
}
int dfs4(int n, int k)
{
	int top = -1;
	int stack[6];
	stack[++top] = n; // push()
	visited[n] = 1;
	while(top!=-1) // 스택이 비어있지 않으면 
	{
		n = stack[top--]; // pop()
		if(n == k)
			return 1;
		for(int i = 1; i<=V; i++)
		{
			if(adj[n][i]!=0 && visited[i]==0) // 인접하고, 미방문인 노드 
			{
				stack[++top] = i;
				visited[i] = 1;
			}
		}
	}
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
// n에서 출발, k에 도착할 수 있으면 1, 아니면 0 리턴 
int dfs3(int n, int k)
{
	if(n == k)
	{
		return 1;
	}
	else
	{
		visited[n] = 1;
		for(int i = 1; i<=V; i++)
		{
			if(adj[n][i]!=0 && visited[i]==0) // 인접하고, 미방문인 노드로 이동 
			{
				if(dfs3(i, k) == 1)
					return 1;
			}
		}
		return 0;
	}
}
