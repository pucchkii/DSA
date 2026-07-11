class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> adj;
        vector<int> result(n+1,INT_MAX);
        vector<int> parent(n+1);

        for(auto & time : times){
            int u=time[0];
            int v=time[1];
            int d=time[2];
            adj[u].push_back({v,d});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({k,0});
        result[k]=0;

        for(int i=1 ; i<=n ; i++){
            parent[i]=i;
        }
        while(!pq.empty()){
            int node=pq.top().first;
            int dist=pq.top().second;
            pq.pop();
            for(auto &vec : adj[node]){
                int adjNode=vec.first;
                int d=vec.second;
                if(d+dist<result[adjNode]){
                    result[adjNode]=d+dist;
                    parent[adjNode]=node;
                    pq.push({adjNode,d+dist});
                }
            }
        }
        int maxi=INT_MIN;
        for(int i=1 ; i<=n ; i++){
            maxi=max(maxi,result[i]);
        }
        if(maxi==INT_MAX){
            return -1;
        }else return maxi;
        
    }
};