#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <stack>
#include <climits>
using namespace std;

class Solution {
  public:
    void dfs(int node, unordered_map<int, list<pair<int, int>>> &adj,
             vector<bool> &visited, stack<int> &topo) {
        visited[node] = true;
        for (auto neighbour : adj[node]) {
            if (!visited[neighbour.first]) {
                dfs(neighbour.first, adj, visited, topo);
            }
        }
        topo.push(node);
    }

    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // Step 0: Create adjacency list using unordered_map
        unordered_map<int, list<pair<int, int>>> adj;
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
        }

        // Step 1: Topological Sort
        vector<bool> visited(V, false);
        stack<int> topo;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited, topo);
            }
        }

        // Step 2: Initialize distances
        vector<int> dist(V, INT_MAX);
        dist[0] = 0;

        // Step 3: Relax edges in topological order
        while (!topo.empty()) {
            int u = topo.top();
            topo.pop();

            if (dist[u] != INT_MAX) {
                for (auto &p : adj[u]) {
                    int v = p.first;
                    int wt = p.second;
                    if (dist[v] > dist[u] + wt) {
                        dist[v] = dist[u] + wt;
                    }
                }
            }
        }

        // Step 4: Convert unreachable distances to -1
        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX)
                dist[i] = -1;
        }

        return dist;
    }
};

// MAIN FUNCTION (from your image)
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";

        cout << "~" << "\n";
    }
}
