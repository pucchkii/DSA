class Solution {
public:
    // memoization
    int t[101][101];
    int n,m;
    int solve(vector<vector<int>>& grid, int i, int j){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==1){
            return 0;
        }
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }

        int right=solve(grid,i+1,j);
        int down=solve(grid,i,j+1);

        return t[i][j]=right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        memset(t,-1,sizeof(t));

        return solve(grid,0,0);
    }
};