#include <iostream>
#include <climits>
using namespace std;

#define MAX_V 100 // Maximum number of vertices

int V; // Number of vertices

int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
    {
        if (mstSet[v] == false && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void printMST(int parent[], int graph[MAX_V][MAX_V])
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " \t"
             << graph[i][parent[i]] << " \n";
}

void primMST(int graph[MAX_V][MAX_V])
{
    int parent[MAX_V];
    int key[MAX_V];
    bool mstSet[MAX_V];

    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && 
                graph[u][v] < key[v])
            {
                parent[v] = u;
                key[V] = graph[u][v];
            }
    }

    printMST(parent, graph);
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

    int graph[MAX_V][MAX_V] = {0};

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

    primMST(graph);

    return 0;
}
