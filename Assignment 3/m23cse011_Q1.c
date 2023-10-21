#include <stdio.h>

#define MAX_NODES 1001
#define MAX_EDGES 5001

int adjacency[MAX_NODES][MAX_NODES];
int color[MAX_NODES];

int isSafe(int node, int col, int N) {
    for (int i = 1; i <= N; i++) {
        if (adjacency[node][i] && col == color[i]) {
            return 0;
        }
    }
    return 1;
}

int assignColors(int node, int N) {
    if (node == N + 1) {
        int maxColor = 0;
        for (int i = 1; i <= N; i++) {
            if (color[i] > maxColor) {
                maxColor = color[i];
            }
        }
        return maxColor;
    }

    for (int c = 1; c <= N; c++) {
        if (isSafe(node, c, N)) {
            color[node] = c;
            int result = assignColors(node + 1, N);
            if (result > 0) {
                return result;
            }
            color[node] = 0;
        }
    }

    return 0;
}

int findMinimumRegisters(int N, int E, int edgesU[], int edgesV[]) {
    for (int i = 0; i < E; ++i) {
        adjacency[edgesU[i]][edgesV[i]] = 1;
        adjacency[edgesV[i]][edgesU[i]] = 1;
    }
    
    int maxCol = assignColors(1, N);
    
    return maxCol;
}

int main() {
    int N, E;
    scanf("%d %d", &N, &E);
    int edgesU[MAX_EDGES], edgesV[MAX_EDGES];
    for (int i = 0; i < E; ++i) {
        scanf("%d %d", &edgesU[i], &edgesV[i]);
        edgesU[i]++;
        edgesV[i]++;
    }
    
    int result = findMinimumRegisters(N, E, edgesU, edgesV);
    printf("%d\n", result);
    
    return 0;
}
