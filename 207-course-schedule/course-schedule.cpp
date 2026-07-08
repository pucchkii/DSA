class Solution {
public:
    bool isCycleDFS( unordered_map<int,vector<int>>& adj, int u , vector<bool>& visited, vector<bool>& inrecursion){
        visited[u]=true;
        inrecursion[u]=true;

        for(auto& v: adj[u]){
            if(!visited[v] && isCycleDFS(adj,v,visited,inrecursion)){
                return true;
            }else if(inrecursion[v]==true){
                return true;
            }
        }
        inrecursion[u]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // ...using DFS
        unordered_map<int,vector<int>> adj;

        for(auto & e : prerequisites){
            int a=e[0];
            int b=e[1];
            adj[b].push_back(a);
        }
        vector<bool> visited(numCourses,false);
        vector<bool> inrecursion(numCourses,false);
        for(int i=0 ; i<numCourses ; i++){
            if(!visited[i] && isCycleDFS(adj,i,visited,inrecursion)){
                return false;
            }
        }
        return true;
    }
};