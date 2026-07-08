class Solution {
public:
    bool hasCycle;
    void dfs(unordered_map<int,vector<int>> &adj, int u, vector<bool>& visited, vector<bool>& inRecursion, stack<int>& st){
        visited[u]=true;
        inRecursion[u]=true;

        for(int &v : adj[u]){
            if(inRecursion[v]==true){
                hasCycle=true;
                return;
            }
            if(!visited[v]){
                dfs(adj,v,visited,inRecursion,st);
            }
        }
        st.push(u);
        inRecursion[u]=false;

    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // using DFS
        unordered_map<int,vector<int>> adj;
        vector<bool> visited(numCourses,false);
        vector<bool> inRecursion(numCourses,false);

        for(auto &e : prerequisites){
            int a=e[0];
            int b=e[1];
            adj[b].push_back(a);
        }
        hasCycle=false;
        stack<int> st;
        for(int i=0 ; i<numCourses ; i++){
            if(!visited[i]){
                dfs(adj,i,visited,inRecursion,st);
            }
        }
        if(hasCycle){
            return {};
        }

        vector<int> result;
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        return result;

        
    }
};