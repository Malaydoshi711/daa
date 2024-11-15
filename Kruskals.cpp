#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class UnionFind {
public:


    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int u) {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }

private:
    vector<int> parent, rank;
};

void kruskalMST(vector<Edge>& edges, int V) {
    sort(edges.begin(), edges.end());
    UnionFind uf(V);
    vector<Edge> mst;
    for (vector<Edge>::iterator it = edges.begin(); it != edges.end(); ++it) {
        if (uf.find(it->u) != uf.find(it->v)) {
            mst.push_back(*it);
            uf.unite(it->u, it->v);
        }
    }
    for (vector<Edge>::iterator it = mst.begin(); it != mst.end(); ++it) {
        cout << "Edge: " << it->u << " - " << it->v << " with weight " << it->weight << endl;
    }
}

int main() {
    int V, E;

    cout << "Enter the number of vertices: ";
    cin >> V;

    cout << "Enter the number of edges: ";
    cin >> E;

    vector<Edge> edges(E);
    cout << "Enter the edges in the format: u v weight\n";
    for (int i = 0; i < E; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    kruskalMST(edges, V);

    return 0;
}