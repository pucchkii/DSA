class Solution {
public:
    bool hasCycleDFS(unordered_map<int,vector<int>> &adj,int u, vector<bool>&visited, vector<bool>& inRecursion){
        visited[u]=true;
        inRecursion[u]=true;

        for(auto& v : adj[u]){
            if(!visited[v]){
                if(hasCycleDFS(adj,v,visited,inRecursion)){
                    return true;
                }
            }else if(inRecursion[v]==true){
                return true;
            }
        }
        inRecursion[u]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;

        vector<bool> visited(numCourses,false);
        vector<bool> inRecuriosn(numCourses,false);

        for(auto &it : prerequisites){
            int u=it[0];
            int v=it[1];

            adj[u].push_back(v);
        }
        for(int i=0 ; i<numCourses ; i++){
            if(!visited[i] && hasCycleDFS(adj,i,visited,inRecuriosn)){
                return false;
            }
        }
        return true;

        
    }
};