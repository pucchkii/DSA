class Solution {
public:
    bool isSafe(int x , int y , int m , int n){
        if(x >= 0 && x < m && y >= 0 && y < n){
            return true;
        }

        return false;
    }
    vector<vector<int>>directions{{1,1},{1,0},{0,1},{-1,-1},{-1,0},{0,-1},{-1,1},{1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(m == 0 || n == 0 || grid[0][0] == 1){
            return -1;
        }
        
        // pair<int , pair<int , int>>P;

        priority_queue<pair<int , pair<int , int>> , vector<pair<int , pair<int , int>>> , greater<pair<int , pair<int , int>>>>pq;
        vector<vector<int>>result(m , vector<int>(n,INT_MAX));
        

        result[0][0] = 0;
        pq.push({0,{0,0}});
        grid[0][0] = 1;

        while(!pq.empty()){
            int distance = pq.top().first;
            auto coordinate = pq.top().second;
            int x = coordinate.first;
            int y = coordinate.second;
            pq.pop();
            if(distance > result[x][y]){
                continue;
            }
            

            for(auto &dir : directions){
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if(isSafe(x_,y_,m,n) && grid[x_][y_] != 1){
                    if(result[x_][y_] > distance + 1){
                        result[x_][y_] = distance + 1;
                        pq.push({1+distance , {x_,y_}});
                        grid[x_][y_] = 1;
                    }
                }
                
            }


        }

        if(result[m-1][n-1] == INT_MAX){
            return -1;
        }
        return result[m-1][n-1] + 1;

    }
};