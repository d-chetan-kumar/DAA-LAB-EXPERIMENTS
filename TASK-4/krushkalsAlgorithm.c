#include <stdio.h>
#include <stdlib.h>
#define V 7   
#define E 11  
struct Edge {
    int src, dest, weight;
};
struct Subset {
    int parent;
    int rank;
};
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}
void Union(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
int compare(const void *a, const void *b) {
    return ((struct Edge *)a)->weight - ((struct Edge *)b)->weight;
}
void KruskalMST(struct Edge edges[]) {
    struct Edge result[V];
    int e = 0, i = 0;
    qsort(edges, E, sizeof(edges[0]), compare);
    struct Subset subsets[V];
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    while (e < V - 1 && i < E) {
        struct Edge next = edges[i++];
        int x = find(subsets, next.src);
        int y = find(subsets, next.dest);
        if (x != y) {
            result[e++] = next;
            Union(subsets, x, y);
        }
    }
    int total = 0;
    printf("Edge \tWeight\n");
    for (i = 0; i < e; i++) {
        printf("%c - %c \t%d\n",
               result[i].src + 'A',
               result[i].dest + 'A',
               result[i].weight);
        total += result[i].weight;
    }
    printf("Total MST Cost = %d\n", total);
}
int main() {
    struct Edge edges[E] = {
        {0,1,7},  
        {0,3,5},  
        {1,2,8}, 
        {1,3,9},  
        {1,4,7},   
        {2,4,5},  
        {3,4,15},  
        {3,5,6},   
        {4,5,8},   
        {4,6,9},   
        {5,6,11}   
    };
    KruskalMST(edges);
    return 0;
}
