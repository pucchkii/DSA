class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        unordered_map<int,vector<int>> adj;
        int cnt=0;
        vector<int> indegree(n,0);
        vector<bool> visited(n,false);
        queue<int> q;
        
        for(auto &edge : prerequisites){
            int a=edge[0];
            int b=edge[1];
            indegree[a]++;
            adj[b].push_back(a);
        }


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
};