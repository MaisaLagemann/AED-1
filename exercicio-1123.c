#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define INF 100000
#define MAXSIZE 101010

int visited[MAXSIZE];
int distance[MAXSIZE];

typedef struct _edge
{

    int node, weight;
    struct _edge *next;

} edge_t;

typedef struct _graph
{

    edge_t *adjacency_list;

} graph_t;

graph_t *create_graph(int);
edge_t *create_edge(int, int);
void run_dijkstra(graph_t *, int, int);
void add_edge(graph_t *, int, int, int);

int main(int argc, char **argv)
{

    int i;
    int num_nodes, num_edges, threshold, start_node, u, v, w;

    while (scanf("%d %d %d %d", &num_nodes, &num_edges, &threshold, &start_node), (threshold && num_nodes && num_edges && start_node))
    {

        graph_t *graph = create_graph(num_nodes + 1);

        for (i = 0; i < num_edges; ++i)
        {

            scanf("%d %d %d", &u, &v, &w);

            if (u >= threshold && v >= threshold || ((u < threshold) && (v < threshold) && (abs(u - v) == 1)))
                add_edge(graph, u, v, w), add_edge(graph, v, u, w);

            if (u >= threshold && v < threshold)
                add_edge(graph, v, u, w);

            if (v >= threshold && u < threshold)
                add_edge(graph, u, v, w);
        }

        run_dijkstra(graph, start_node, num_nodes);
        printf("%d\n", distance[threshold - 1]);
    }

    return 0;
}

void run_dijkstra(graph_t *g, int start, int num_nodes)
{

    edge_t *e;
    int i, j, current_node;

    for (i = 0; i < num_nodes; ++i)
        distance[i] = INF;

    memset(visited, false, sizeof(visited));

    distance[start] = 0;

    for (i = 0; i < num_nodes; ++i)
    {

        current_node = -1;

        for (j = 0; j < num_nodes; ++j)
            if (!visited[j] && (current_node == -1 || distance[j] < distance[current_node]))
                current_node = j;

        if (distance[current_node] == INF)
            break;

        visited[current_node] = true;

        for (e = g->adjacency_list[current_node].next; e != NULL; e = e->next)
        {

            int next_node = e->node;
            int edge_weight = e->weight;

            if (distance[current_node] + edge_weight < distance[next_node])
                distance[next_node] = distance[current_node] + edge_weight;
        }
    }
}

graph_t *create_graph(int num_nodes)
{

    int i;
    graph_t *g = (graph_t *)malloc(sizeof(graph_t));
    g->adjacency_list = (edge_t *)malloc(sizeof(edge_t) * (num_nodes + 1));

    for (i = 0; i < num_nodes; ++i)
        g->adjacency_list[i].next = NULL;

    return g;
}

edge_t *create_edge(int node, int weight)
{

    edge_t *new_edge = (edge_t *)malloc(sizeof(edge_t));

    new_edge->node = node;
    new_edge->weight = weight;
    new_edge->next = NULL;

    return new_edge;
}

void add_edge(graph_t *g, int u, int v, int w)
{

    edge_t *new_edge = create_edge(u, w);
    new_edge->next = g->adjacency_list[v].next;
    g->adjacency_list[v].next = new_edge;
}