class Solution {
public:
    int n,m;
    typedef long long ll;
    int MOD =1e9+7;

    int maxProductPath(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();

        // bottom up dp lena padega
        vector<vector<pair<ll,ll>>> t(m,vector<pair<ll,ll>>(n));
        // t[i][j] = (maxVal , minval) to reach form (0,0) to (i,j);

        t[0][0] = make_pair(grid[0][0], grid[0][0]);

        // filling the first row
        for(int j=1 ; j<n ; j++){
            t[0][j].first  = t[0][j-1].first * grid[0][j]; //maxVal
            t[0][j].second = t[0][j-1].second * grid[0][j]; //minVal
        }

        // filling the first col
        for(int i=1 ; i<m ; i++){
            t[i][0].first  = t[i-1][0].first * grid[i][0]; //maxVal
            t[i][0].second = t[i-1][0].second * grid[i][0]; //minVal
        }
        for(int i=1 ; i<m ; i++){
            for(int j=1 ; j<n ; j++){
                ll upMax = t[i-1][j].first;
                ll upMin = t[i-1][j].second;

                ll leftMax = t[i][j-1].first;
                ll rightMin = t[i][j-1].second;

                t[i][j].first = max({upMax * grid[i][j],upMin * grid[i][j],leftMax * grid[i][j],rightMin * grid[i][j]});

                t[i][j].second = min({upMax * grid[i][j],upMin * grid[i][j],leftMax * grid[i][j],rightMin * grid[i][j]});

            }
        }
        auto [maxProd, minProd] = t[m-1][n-1];
        return maxProd < 0 ? -1 : maxProd % MOD;
    }

};