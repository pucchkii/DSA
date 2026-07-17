class Solution {
public:
    void dfs(int u, unordered_map<int, vector<int>>& adj,vector<bool>& visited, int& nodes, int& degreeSum) {

        visited[u] = true;
        nodes++;
        degreeSum += adj[u].size();

        for (int v : adj[u]) {
            if (!visited[v]) {
                dfs(v, adj, visited, nodes, degreeSum);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        int complete = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int nodes = 0;
                int degreeSum = 0;

                dfs(i, adj, visited, nodes, degreeSum);

                int edgeCount = degreeSum / 2;

                if (edgeCount == nodes * (nodes - 1) / 2) {
                    complete++;
                }
            }
        }

        return complete;
    }
};