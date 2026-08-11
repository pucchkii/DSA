class Solution {
public:
    int n,m;
    void dfs(int i, int j, vector<vector<char>>& grid){
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]=='0'){
            return ;
        }
        grid[i][j]='0';
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        n=grid.size();
        m=grid[0].size();
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j]=='1'){
                    dfs(i,j,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};