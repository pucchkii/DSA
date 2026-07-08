class Solution {
public:
    bool topologicalSort(unordered_map<int,vector<int>> &adj, int n, vector<int>&indegree){
        queue<int> q;
        int cnt=0;
        for(int i=0 ; i<n ; i++){
            if(indegree[i]==0){
                q.push(i);
                cnt++;
            }
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int v : adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                    cnt++;
                }
            }
        }
        return cnt==n;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(numCourses,0);
        
        for(auto &edge : prerequisites){
            int a=edge[0];
            int b=edge[1];
            indegree[a]++;
            adj[b].push_back(a);
        }


        return topologicalSort(adj,numCourses,indegree);


        
    }
};