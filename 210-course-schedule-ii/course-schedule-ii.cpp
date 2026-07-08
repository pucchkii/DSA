class Solution {
public:
    vector<int> topologicalOrder( unordered_map<int,vector<int>> &adj, int n, vector<int>& indegree){
        int cnt=0;
        queue<int> q;

        vector<int> res;
        
        for(int i=0 ; i<n ; i++){
            if(indegree[i]==0){
                q.push(i);
                res.push_back(i);
                cnt++;
            }
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int &v : adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                    res.push_back(v);
                    cnt++;
                }
            }
        }
        if(cnt==n){
            return res;
        }else{
            return {};
        }
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(numCourses,0);

        for(auto & edge : prerequisites){
            int a=edge[0];
            int b=edge[1];
            indegree[a]++;
            adj[b].push_back(a);
        }
        return topologicalOrder(adj,numCourses,indegree);
    }
};