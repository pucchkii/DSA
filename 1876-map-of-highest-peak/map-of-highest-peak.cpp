class Solution {
public:
    typedef pair<int,int> P;
    vector<vector<int>> directions{{-1,0},{1,0},{0,1},{0,-1}};  
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size();
        int m=isWater[0].size();

        queue<P> q;
        vector<vector<int>> heights(n,vector<int>(m,0));
        vector<vector<bool>> visited(n,vector<bool>(m,false));

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(isWater[i][j]==1){
                    heights[i][j]=0;
                    visited[i][j]=true;
                    q.push({i,j});
                }
            }
        }
        auto isSafe=[&](int x, int y){
            return (x>=0 && x<n && y>=0 && y<m && !visited[x][y]);
        };

        while(!q.empty()){
            int N=q.size();
            while(N--){
                auto curr=q.front();
                q.pop();

                int x=curr.first;
                int y=curr.second;

                for(auto & dir : directions){
                    int new_x = x + dir[0];
                    int new_y = y + dir[1];

                    if(isSafe(new_x,new_y)){
                        heights[new_x][new_y]=heights[x][y] + 1;;
                        visited[new_x][new_y]=true;
                        q.push({new_x,new_y});
                    }
                }
            }           
        }
        return heights;
    }
};