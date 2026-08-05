class Solution {
public:
    int m,n;
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m=dungeon.size();
        n=dungeon[0].size();

        vector<vector<int>> t(m,vector<int>(n,0));

        for(int i=m-1 ; i>=0 ; i--){
            for(int j=n-1 ; j>=0 ; j--){
                if(i==m-1 && j==n-1){
                    t[i][j] = (dungeon[i][j]>0) ? 1 : abs(dungeon[i][j])+1;
                }else{
                    int right = (j+1>=n) ? 1e9 : t[i][j+1];
                    int down  = (i+1>=m) ? 1e9 : t[i+1][j]; 

                    int result = min(right,down)-dungeon[i][j];

                    t[i][j] = (result > 0) ? result : 1;
                }

            }
        }
        return t[0][0];

    }
};