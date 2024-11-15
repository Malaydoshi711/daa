#include <iostream>
#include <limits.h>
using namespace std;

#define MAX_V 100 // Maximum number of vertices

int V; // Number of vertices

int minDistance(int dist[], bool visited[])
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (visited[v] == false && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    return min_index;
}

void printSolution(int dist[])
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t" << dist[i] << endl;
}

void dijkstra(int graph[MAX_V][MAX_V], int src)
{
    int dist[MAX_V];
    bool visited[MAX_V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, visited[i] = false;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, visited);
        visited[u] = true;

        for (int v = 0; v < V; v++){
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }

    printSolution(dist);
}

int main()
{
    cout << "Enter the number of vertices (max " << MAX_V << "): ";
    cin >> V;

    if (V <= 0 || V > MAX_V)
    {
        cout << "Invalid number of vertices. Please enter a number between 1 and " << MAX_V << ".\n";
        return 1;
    }

    int graph[MAX_V][MAX_V];

    cout << "Enter the adjacency matrix (" << V << "x" << V << "):\n";
    cout << "Use 0 for no edge, and positive integer for edge weight.\n";

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] < 0)
            {
                cout << "Invalid weight. Please enter non-negative integers only.\n";
                return 1;
            }
        }
    }

    int src;
    cout << "Enter the source vertex (0 to " << V - 1 << "): ";
    cin >> src;

    if (src < 0 || src >= V)
    {
        cout << "Invalid source vertex. Please enter a number between 0 and " << V - 1 << ".\n";
        return 1;
    }

    dijkstra(graph, src);

    return 0;
}