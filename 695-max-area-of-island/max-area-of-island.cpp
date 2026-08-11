class Solution {
public:
    int n,m;

    int DFS(vector<vector<int>>& grid,int i,int j){
        if(i<0||j<0||i>=n||j>=m||grid[i][j]==0)
            return 0;

        grid[i][j]=0;

        int ans=1;
        ans+=DFS(grid,i+1,j);
        ans+=DFS(grid,i-1,j);
        ans+=DFS(grid,i,j+1);
        ans+=DFS(grid,i,j-1);

        return ans;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid){
        n=grid.size();
        m=grid[0].size();

        int res=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    res=max(res,DFS(grid,i,j));
                }
            }
        }

        return res;
    }
};