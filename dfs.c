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
    int n, startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // Initialize visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);

    printf("DFS traversal starting from vertex %d: ", startVertex);
    dfs(startVertex, n);
    printf("\n");

    return 0;
}
