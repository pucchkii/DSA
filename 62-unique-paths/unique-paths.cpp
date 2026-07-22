class Solution {
public:
    int t[101][101];

    int solve(int i, int j, int m, int n){
        if(i==m-1 && j==n-1)
            return 1;
        if(i>=m || j>=n){
            return 0;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        int takeDown=solve(i+1,j,m,n);
        int takeRight=solve(i,j+1,m,n);

        return t[i][j]=takeDown+takeRight;
    }
    int uniquePaths(int m, int n) {
        memset(t,-1,sizeof(t));
        return solve(0,0,m,n);
        
    }
};