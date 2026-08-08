class Solution {
public:
    void bfs(unordered_map<int,vector<int>> &adj, int k, vector<bool>& suspicious, vector<int>& indegree){
        queue<int> q;
        q.push(k);

        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto & neigh : adj[u]){
                indegree[neigh]--;
                if(suspicious[neigh]==false){
                    suspicious[neigh]=true;
                    q.push(neigh);

                }
            }

        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        // unordered map, suspicous vector and undegree vector
        unordered_map<int,vector<int>> adj;
        vector<bool> suspicious(n,false);
        vector<int> indegree(n,0);

        for(auto &e : invocations){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        // mark kth node suspicious
        suspicious[k]=true;

        // travel bfs from suspicious kth node
        bfs(adj,k,suspicious,indegree);

        // mark the ans
        vector<int> ans;
        bool cannotremove=false;
        for(int i=0 ; i<n ; i++){
            if(suspicious[i] && indegree[i]>0){
                cannotremove=true;
                break;
            }else if(!suspicious[i]){
                ans.push_back(i);
            }
        }
        if(cannotremove){
            vector<int> vec(n);
            for(int i=0 ; i<n ; i++){
                vec[i]=i;
            }
            return vec;
        }

        return ans;
    }
};
