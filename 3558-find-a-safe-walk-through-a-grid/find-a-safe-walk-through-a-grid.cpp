class Solution {
public:
    vector<vector<int>> directions{{-1,0},{1,0},{0,1},{0,-1}};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> result(n,vector<int>(m,INT_MAX));
        //result[i][j] = min health to reach form [0][0] to [i][j];

        deque<pair<int,int>> dq;
        result[0][0]=grid[0][0];
        
        dq.push_front({0,0});

        while(!dq.empty()){
            auto[r,c]=dq.front();
            dq.pop_front();

            for(auto &dir : directions){
                int nr = r + dir[0];
                int nc = c + dir[1];

                if(nr<0 || nr>=n || nc<0 || nc>=m) continue;

                if(result[nr][nc]>result[r][c]+grid[nr][nc]){
                    result[nr][nc]=result[r][c]+grid[nr][nc];

                    if(grid[nr][nc]==0){
                        dq.push_front({nr,nc});
                    }else{
                        dq.push_back({nr,nc});
                    }
                }
            }
        }
        int x=result[n-1][m-1];
        return health-x>=1;
    }
};