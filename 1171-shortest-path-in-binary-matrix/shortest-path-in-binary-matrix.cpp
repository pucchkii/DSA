class Solution {
public:

    typedef pair<int,pair<int,int>> P;

    vector<vector<int>> directions{{1,1},{0,1},{1,0},{-1,0},{0,-1},{-1,-1},{1,-1},{-1,1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        if(n==0 || m==0 || grid[0][0]!=0){
            return -1;
        }

        auto isSafe=[&](int x, int y){
            return x>=0 && x<n && y>=0 && y<m;
        };

        //priority_queue<P,vector<P> , greater<P>> q;
        queue<P> q;
        vector<vector<int>> result(n,vector<int>(m,INT_MAX));

        q.push({0,{0,0}});
        result[0][0]=0;

        while(!q.empty()){
            int d=q.front().first;
            pair<int,int> node = q.front().second;
            int x=node.first;
            int y=node.second;
            q.pop();

            for(auto & dir : directions){
                int x_ = x + dir[0];
                int y_ = y + dir[1];
                int dist=1;

                if(isSafe(x_ , y_) && grid[x_][y_]==0 && d+dist<result[x_][y_]){
                    result[x_][y_]=d+dist;
                    q.push({d+dist,{x_,y_}});
                }
            }
        }
        if(result[n-1][m-1]==INT_MAX){
            return -1;
        }else{
            return result[n-1][m-1]+1;
        }


    }
};