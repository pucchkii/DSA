class Solution {
public:
    void bfs(unordered_map<int,vector<int>> &adj, int u , vector<bool>& visited){
        visited[u]=true;
        queue<int> q;
        q.push(u);

        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(auto& v: adj[curr]){
                if(!visited[v]){
                    bfs(adj,v,visited);

                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        // using bfs
        int n=isConnected.size(), cnt=0;
        // adj list
        unordered_map<int,vector<int>> adj;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool> visited(n,false);
        for(int i=0 ; i<n ; i++){
            if(!visited[i]){
                bfs(adj,i,visited);
                cnt++;
            }
        }
        return cnt;
        
    }
};