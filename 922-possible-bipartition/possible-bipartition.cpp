class Solution {
public:
    bool bfs(unordered_map<int,vector<int>> &adj, int curr, vector<int>& color, int currColor){
        color[curr]=currColor;
        queue<int> q;
        q.push(curr);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int &v : adj[u]){
                if(color[v]==color[u]){
                    return false;
                }else if(color[v]==-1){
                    color[v]=1-color[u];
                    q.push(v);
                }
            }
        }
        return true;


    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int,vector<int>> adj;

        for(auto& e : dislikes){
            int u=e[0];
            int v=e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> color(n+1,-1);
        int currColor=1;

        for(int i=1 ; i<=n ; i++){
            if(color[i]==-1){
                if(bfs(adj,i,color,currColor)==false){
                    return false;
                }
            }
        }
        return true;
    }
};