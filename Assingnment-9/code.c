
#include <stdio.h>

#define V 5

// Find the vertex with minimum key value
int minKey(int key[], int mst[]) {
    int min = 999, min_index;

    for (int i = 0; i < V; i++) {
        if (mst[i] == 0 && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

// Implement Prim's algorithm
void primMST(int graph[V][V]) {
    int parent[V];
    int key[V];
    int mst[V];

    // Initialize values
    for (int i = 0; i < V; i++) {
        key[i] = 999;
        mst[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mst);
        mst[u] = 1;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0 && mst[v] == 0 &&
                graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Display Minimum Spanning Tree
    int total = 0;

    printf("Edge \tWeight\n");

    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d\n",
               parent[i], i, graph[i][parent[i]]);
        total += graph[i][parent[i]];
    }

    printf("Total MST Weight = %d\n", total);
}

int main() {

    // Graph using adjacency matrix
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph);

    return 0;
}
