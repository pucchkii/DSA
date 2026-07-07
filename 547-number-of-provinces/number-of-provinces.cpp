class Solution {
public:
    
    void explore(int node, vector<vector<int>>& isConnected,vector<int>& visited) {
        
        visited[node] = 1;

        int n = isConnected.size();

        for (int next = 0; next < n; next++) {
            if (isConnected[node][next] == 1 && !visited[next]) {
                explore(next, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<int> visited(n, 0);
        int provinceCount = 0;

        for (int city = 0; city < n; city++) {
            if (!visited[city]) {
                provinceCount++;
                explore(city, isConnected, visited);
            }
        }

        return provinceCount;
    }
};