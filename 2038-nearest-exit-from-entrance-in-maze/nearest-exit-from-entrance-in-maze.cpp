class Solution {
public:
    vector<vector<int>> directions{{-1,0},{0,1},{1,0},{0,-1}};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        // attempting bfs

        int n=maze.size();
        int m=maze[0].size();

        vector<vector<bool>> visited(n,vector<bool>(m,false));

        int i = entrance[0];
        int j = entrance[1];

        queue<pair<int,int>> q;
        visited[i][j]=true;

        auto isSafe=[&](int x, int y){
            return (x>=0 && x<n && y>=0 && y<m);
        };

        auto isBoundary=[&](int x, int y){
            return (x==0 || x==n-1 || y==0 || y==m-1);
        };

        q.push({i,j});
        int travel=0;
        while(!q.empty()){
            int N=q.size();
            while(N--){
                auto node=q.front();
                q.pop();
            
                int x=node.first;
                int y=node.second;

                for(auto& dir : directions){
                    int new_x = x + dir[0];
                    int new_y = y + dir[1];

                    if(isSafe(new_x,new_y) && !visited[new_x][new_y] && maze[new_x][new_y]!='+' ){
                        visited[new_x][new_y]=true;
                        q.push({new_x,new_y});
                        if(isBoundary(new_x,new_y)) return travel+1;
                    }
                }
            }
            travel++;

        }
        return -1;

    }
};