class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n,m;
        n=grid.size();
        m=grid[0].size();

        vector<vector<int>> t(n,vector<int>(m));
        // state definition :
        // t[i][j] --> indicates no of ways to reach (i,j) from (0,0);

        t[0][0]=1; // distance form source to source is 0;
        for(int i=0 ; i<m ; i++){
            if(grid[0][i]==1){
                break;
            }else{
                t[0][i]=1;
            }
        }
        if(grid[n-1][m-1]==1){
            return 0;
        }
        for(int i=0 ; i<n ; i++){
            if(grid[i][0]==1){
                break;
            }else{
                t[i][0]=1;
            }
        }

        for(int i=1 ; i<n ; i++){
            for(int j=1 ; j<m ; j++){
                if(grid[i][j]==1){
                    t[i][j]=0;
                }else{
                    t[i][j]=t[i-1][j]+t[i][j-1];
                }
            }
        }
       
        return t[n-1][m-1];
    }
};