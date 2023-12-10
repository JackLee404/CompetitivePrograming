#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX_NODES = 6000; 
const int INF = 1e9;

struct Edge {
    int to;
    int capacity;
    int flow;
    int reverseEdgeIndex;
};

vector<Edge> graph[MAX_NODES];
int level[MAX_NODES];
int nextEdgeIndex[MAX_NODES];

void addEdge(int from, int to, int capacity) {
    graph[from].push_back({to, capacity, 0, static_cast<int>(graph[to].size())});
    graph[to].push_back({from, 0, 0, static_cast<int>(graph[from].size()) - 1});
}

// Breadth-First Search to find level graph
bool bfs(int source, int sink) {
    fill(level, level + MAX_NODES, -1);
    level[source] = 0;
    queue<int> q;
    q.push(source);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (const auto& edge : graph[u]) {
            if (level[edge.to] == -1 && edge.flow < edge.capacity) {
                level[edge.to] = level[u] + 1;
                q.push(edge.to);
            }
        }
    }

    return level[sink] != -1;
}

// Depth-First Search to find blocking flow
int dfs(int u, int sink, int minCapacity) {
    if (u == sink) {
        return minCapacity;
    }

    for (int& i = nextEdgeIndex[u]; i < graph[u].size(); ++i) {
        Edge& edge = graph[u][i];
        if (level[edge.to] == level[u] + 1 && edge.flow < edge.capacity) {
            int bottleneck = dfs(edge.to, sink, min(minCapacity, edge.capacity - edge.flow));
            if (bottleneck > 0) {
                edge.flow += bottleneck;
                graph[edge.to][edge.reverseEdgeIndex].flow -= bottleneck;
                return bottleneck;
            }
        }
    }

    return 0;
}

// Dinitz's algorithm to find maximum flow
int dinitz(int source, int sink) {
    int maxFlow = 0;
    while (bfs(source, sink)) {
        fill(nextEdgeIndex, nextEdgeIndex + MAX_NODES, 0);
        int flow;
        while ((flow = dfs(source, sink, INF)) > 0) {
            maxFlow += flow;
        }
    }
    return maxFlow;
}

int main() {
    int n;
    cin >> n;

    int source = 0;
    int sink = 2 * n + 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = n + 1; j <= 2 * n; ++j) {
            int capacity;
            cin >> capacity;
            if (capacity == 1) {
                addEdge(i, j, 1);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        addEdge(source, i, 1);
    }

    for (int j = n + 1; j <= 2 * n; ++j) {
        addEdge(j, sink, 1);
    }

    int maxMatching = dinitz(source, sink);
    cout << maxMatching << endl;

    return 0;
}
