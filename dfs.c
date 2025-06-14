#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];    // Adjacency matrix
int visited[MAX];     // Visited array
int stack[MAX];       // Stack
int top = -1;

// Push function
void push(int v) {
    stack[++top] = v;
}

// Pop function
int pop() {
    return stack[top--];
}

// Check if stack is empty
int isEmpty() {
    return top == -1;
}

// DFS using Stack
void dfs(int start, int n) {
    push(start);

    while (!isEmpty()) {
        int v = pop();

        if (!visited[v]) {
            printf("%d ", v);
            visited[v] = 1;

            // Push adjacent vertices in reverse order
            for (int i = n - 1; i >= 0; i--) {
                if (adj[v][i] == 1 && !visited[i]) {
                    push(i);
                }
            }
        }
    }
}

int main() {
    int n, edges, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d%d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // For undirected graph
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS Traversal (non-recursive) starting from %d:\n", start);
    dfs(start, n);

    return 0;
}
