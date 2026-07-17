class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>> adj;
        if(source==destination) return true;
        for(auto & edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n,false);
        visited[source]=true;
        queue<int> q;
        q.push(source);

        while(!q.empty()){
            int N=q.size();
            while(N--){
                int node=q.front();
                q.pop();
                for(auto& v : adj[node]){
                    if(!visited[v]){
                        visited[v]=true;
                        q.push(v);
                        if(v==destination){
                            return true;
                        }
                    }
                }

            }
        }
        return false;
    }
};