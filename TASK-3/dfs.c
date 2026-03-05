#include <stdio.h> 
#define MAX 10 
int graph[MAX][MAX], visited[MAX]; 
void dfs(int node, int n) 
{ 
    int i; 
    visited[node] = 1; 
    printf("%c ", node + 'A');   // Print node 
    for (i = 0; i < n; i++) 
    { 
        if (graph[node][i] == 1 && visited[i] == 0) 
        { 
            dfs(i, n); 
        } 
    } 
} 
int main() 
{ 
    int n, i, j, start; 
    printf("Enter number of nodes: "); 
    scanf("%d", &n); 
    printf("Enter adjacency matrix:\n"); 
    for (i = 0; i < n; i++) 
    { 
        for (j = 0; j < n; j++) 
        { 
            scanf("%d", &graph[i][j]); 
        } 
        visited[i] = 0; 
    } 
    printf("Enter starting node (0 for A, 1 for B, ...): "); 
    scanf("%d", &start); 
 
    printf("DFS Traversal: "); 
    dfs(start, n); 
    return 0; 
}