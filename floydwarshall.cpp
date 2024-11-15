#include <iostream>
using namespace std;

const int INF = 99999; // A large number representing infinity
int V; //number of vertices

void floyd_warshall(int graph[10][10]) {
    
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (graph[i][k] + graph[k][j] < graph[i][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

    cout << "Shortest distances between every pair of vertices:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j] == INF)
                cout << "INF" << "  ";
            else
                cout << graph[i][j] << "  ";
        }
        cout << endl;
    }
}

int main() {
    cout << "Enter the number of vertices: ";
    cin >> V;

    int graph[10][10];

    cout << "Enter the adjacency matrix (use " << INF << " for infinity):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    floyd_warshall(graph);
}
