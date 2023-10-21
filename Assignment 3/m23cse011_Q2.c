#include <stdio.h>
#include <stdbool.h>

#define MAXN 1000
#define MAXE 5000

int N, E;
int U[MAXE], V[MAXE];
int adjacencyList[MAXN][MAXN];

int Coloring() {
    int colors[MAXN];
    bool available[MAXN];

    for (int i = 0; i < N; i++) {
        colors[i] = -1;
        available[i] = true;
    }

    colors[0] = 0;

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (adjacencyList[i][j])
                if (colors[j] != -1)
                    available[colors[j]] = false;
        }

        int cr;
        for (cr = 0; cr < N; cr++) {
            if (available[cr])
                break;
        }

        colors[i] = cr;

        for (int j = 0; j < N; j++) {
            if (adjacencyList[i][j])
                if (colors[j] != -1)
                    available[colors[j]] = true;
        }
    }

    int numColors = 0;
    for (int i = 0; i < N; i++) {
        if (colors[i] > numColors)
            numColors = colors[i];
    }

    return numColors + 1;
}

int main() {
    scanf("%d%d", &N, &E);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            adjacencyList[i][j] = 0;
        }
    }

    for (int i = 0; i < E; i++) {
        scanf("%d%d", &U[i], &V[i]);
        adjacencyList[U[i]][V[i]] = 1;
        adjacencyList[V[i]][U[i]] = 1;
    }

    int result = Coloring();
    printf("%d\n", result);

    return 0;
}
