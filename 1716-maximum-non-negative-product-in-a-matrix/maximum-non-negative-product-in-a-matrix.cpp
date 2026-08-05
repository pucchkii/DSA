class Solution {
public:
    int n,m;
    typedef long long ll;
    int MOD =1e9+7;

    // memoization
    vector<vector<pair<ll,ll>>> t;

    pair<ll,ll> solve(vector<vector<int>>& grid, int i, int j){
        if(i==m-1 && j==n-1){
            return {grid[i][j],grid[i][j]};
        }
        ll maxVal = LLONG_MIN;
        ll minVal = LLONG_MAX;

        if(t[i][j] != make_pair(LLONG_MIN, LLONG_MAX)){
            return t[i][j];
        }

        // DOWN
        if(i+1<m){
            auto [downMax, downMin] = solve(grid, i+1,j);
            maxVal = max ({maxVal , grid[i][j]*downMax, grid[i][j]*downMin});
            minVal = min ({minVal , grid[i][j]*downMax, grid[i][j]*downMin});
        }
        // RIGHT
        if(j+1<n){
            auto [rightMax, rightMin] = solve(grid, i, j+1);
            maxVal = max ({maxVal , grid[i][j]*rightMax, grid[i][j]*rightMin});
            minVal = min ({minVal , grid[i][j]*rightMax, grid[i][j]*rightMin});
        }
        return t[i][j] = {maxVal,minVal};
    }
    int maxProductPath(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();

        // initializing t with LLONG_MIN and LLONG_MAX;
        t = vector<vector<pair<ll,ll>>> (m,vector<pair<ll,ll>> (n, {LLONG_MIN, LLONG_MAX}));
        auto [maxProd, minProd] = solve(grid, 0, 0);

        return maxProd < 0 ? -1 : maxProd % MOD; 
    }
};