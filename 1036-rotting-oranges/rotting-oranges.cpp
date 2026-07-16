class Solution {
public:
    typedef pair<int,int> P;
    vector<vector<int>> directions{{-1,0},{0,1},{1,0},{0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int freshCount=0;
        queue<P> q;

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }else if(grid[i][j]==1){
                    freshCount++;
                }
            }
        }
        if(freshCount==0){
            return 0;
        }
        auto isSafe=[&](int x, int y){
            return (x>=0 && x<n && y>=0 && y<m && grid[x][y]==1);
        };
        int minutes=0;
        while(!q.empty()){
            int N=q.size();
            while(N--){
                P curr=q.front();
                q.pop();

                int i=curr.first;
                int j=curr.second;

                for(auto & dir : directions){
                    int new_i =i + dir[0];
                    int new_j =j + dir[1];
                    if(isSafe(new_i,new_j)){
                        grid[new_i][new_j]=2;
                        q.push({new_i,new_j});
                        freshCount--;
                    }
                }
            }
            minutes++;
        }
        return(freshCount==0) ? minutes-1: -1;

    }
};