class Solution {
public:
    bool dfs(unordered_map<int,vector<int>> &adj, int u, vector<int>& color, int& currColor){
        color[u]=currColor;
        for(auto& v : adj[u]){
            if(color[v]==currColor){
                return false;
            }
            if(color[v]==-1){
                color[v]=1-currColor;
                if(dfs(adj,v,color,color[v])==false){
                    return false;
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        // unordered map
        unordered_map<int,vector<int>> adj;

        for(auto &e : dislikes){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> color(n+1,-1);
        int currColor=1;
        for(int i=0 ; i<n ; i++){
            if(color[i]==-1){
                if(dfs(adj,i,color,currColor)==false){
                    return false;
                }
            }
        }
        return true;
    }
};