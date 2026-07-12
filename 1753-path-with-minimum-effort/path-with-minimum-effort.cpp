class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    vector<vector<int>> directions{{0,1},{1,0},{-1,0},{0,-1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        auto isSafe=[&](int x, int y){
            return x>=0 && x<n && y>=0 && y<m;
        };
        vector<vector<int>> result(n,vector<int>(m,INT_MAX));
        priority_queue<P,vector<P>, greater<P>> pq;

        pq.push({0,{0,0}});
        result[0][0]=0;

        while(!pq.empty()){
            int diff=pq.top().first;
            auto node=pq.top().second;
            int x=node.first;
            int y=node.second;
            pq.pop();

            if(x==n-1 && y==m-1){
                return diff;
            }
            
            for(auto dir : directions){
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if(isSafe(x_,y_)){
                    int absDiff=abs(heights[x][y]-heights[x_][y_]);
                    int maxDiff=max(diff,absDiff);
                    if(result[x_][y_]>maxDiff){
                        result[x_][y_]=maxDiff;
                        pq.push({maxDiff,{x_,y_}});
                    }
                }
            }
        }
        return result[n-1][m-1];
        
    }
};