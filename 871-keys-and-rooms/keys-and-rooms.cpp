class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n=rooms.size();
        vector<bool> visited(n,false);
        visited[0]=true;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto & v : rooms[node]){
                if(!visited[v]){
                    visited[v]=true;
                    q.push(v);
                }
            }
        }
        for(int i=0 ; i<n ; i++){
            if(visited[i]==false){
                return false;
            }
        }
        return true;
    }
};