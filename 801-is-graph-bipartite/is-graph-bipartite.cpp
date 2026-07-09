class Solution {
public:
    bool bfs(vector<vector<int>>& graph, int curr, vector<int>& color, int& currColor){
        color[curr]=currColor;
        queue<int> q;
        q.push(curr);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int & v: graph[u]){
                if(color[v]==color[u]){
                    return false;
                }else if(color[v]==-1){
                    color[v]=1-color[u];
                    q.push(v);
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);

        int currColor=0;
        for(int i=0 ; i<n ; i++){
            if(color[i]==-1){
                if(bfs(graph,i,color,currColor)==false){
                    return false;
                }
            }
        }
        return true;
    }
};