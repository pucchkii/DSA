class Solution {
public:
    // memoize
    int t[201][201];
    int m,n;
    int solve(int i, int j,vector<vector<int>>& dungeon){
        
        if(i>=m || j>=n){
            return 1e7;
        }

        if(t[i][j]!=-1){
            return t[i][j];
        }
        if(i==m-1 && j==n-1){
            if(dungeon[i][j]>0){
                return 1;
            }
            return abs(dungeon[i][j])+1;
        }

        int right = solve(i+1,j,dungeon);
        int down = solve(i,j+1,dungeon);

        int result = min(right,down)-dungeon[i][j];

        return t[i][j]=result > 0 ? result : 1;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m=dungeon.size();
        n=dungeon[0].size();

        memset(t,-1,sizeof(t));
        return solve(0,0,dungeon);
    }
};