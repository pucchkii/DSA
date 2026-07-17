class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x]=find(parent[x]);
    }

    void Union(int x, int y){
        int x_parent=find(x);
        int y_parent=find(y);

        if(x_parent==y_parent){
            return;
        }
        if(rank[x_parent]>rank[y_parent]){
            parent[y_parent]=x_parent;
        }else  if(rank[x_parent]<rank[y_parent]){
            parent[x_parent]=y_parent;
        }else{
            parent[x_parent]=y_parent;
            rank[y_parent]++;
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        //using DSU
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0 ; i<n ; i++){
            parent[i]=i;
        }
        for(auto &edge : edges){
            Union(edge[0], edge[1]);
        }
        return find(source)==find(destination);
    }
};