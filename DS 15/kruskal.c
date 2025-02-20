#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge
struct Edge {
    int u, v, cost;
};

// Structure to represent a subset for Union-Find
struct Subset {
    int parent;
    int rank;
};

// Function to compare two edges (used for sorting)
int compare(const void* a, const void* b) {
    return ((struct Edge*)a)->cost - ((struct Edge*)b)->cost;
}

// Find function with path compression
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Union function by rank
void unionSet(struct Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (rootX != rootY) {
        if (subsets[rootX].rank < subsets[rootY].rank)
            subsets[rootX].parent = rootY;
        else if (subsets[rootX].rank > subsets[rootY].rank)
            subsets[rootY].parent = rootX;
        else {
            subsets[rootY].parent = rootX;
            subsets[rootX].rank++;
        }
    }
}

// Function to implement Kruskal's algorithm
int kruskal(struct Edge edges[], int n, int E, struct Edge t[]) {
    int e = 0;  // Count of edges in MST
    int i = 0;  // Initial index of sorted edges
    int mincost = 0;  // Total cost of MST
    struct Subset *subsets = (struct Subset*) malloc(n * sizeof(struct Subset));

    // Step 1: Sort all edges in non-decreasing order of their weight
    qsort(edges, E, sizeof(edges[0]), compare);

    // Initialize subsets for union-find
    for (i = 0; i < n; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    i = 0;  // Index to iterate over sorted edges
    while (e < n - 1 && i < E) {  // We need exactly n-1 edges in the MST
        struct Edge next_edge = edges[i++];

        int x = find(subsets, next_edge.u);
        int y = find(subsets, next_edge.v);

        // If including this edge does not cause a cycle, include it in the result
        if (x != y) {
            t[e++] = next_edge;
            mincost += next_edge.cost;
            unionSet(subsets, x, y);
        }
    }

    // Free the memory for subsets
    free(subsets);

    return mincost;  // Return the total cost of the MST
}

// Driver program
int main() {
    int n = 4;  // Number of vertices
    int E = 5;  // Number of edges

    // Array of edges (u, v, weight)
    struct Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    struct Edge t[n - 1];  // Array to store edges in the MST

    int totalCost = kruskal(edges, n, E, t);

    // Print the resulting MST
    printf("Edges in the Minimum Spanning Tree (MST):\n");
    for (int i = 0; i < n - 1; i++) {
        printf("%d -- %d == %d\n", t[i].u, t[i].v, t[i].cost);
    }

    // Print the total cost of the MST
    printf("Total cost of the Minimum Spanning Tree: %d\n", totalCost);

    return 0;
}
