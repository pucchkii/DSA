class Solution {
public:
    int m, n;
    int t[201][201];

    int solve(vector<vector<int>>& grid, int i, int j) {

        if (i >= m || j >= n)
            return INT_MAX;

        if (i == m - 1 && j == n - 1)
            return grid[i][j];

        if (t[i][j] != -1)
            return t[i][j];

        int down = solve(grid, i + 1, j);
        int right = solve(grid, i, j + 1);

        return t[i][j] = grid[i][j] + min(down, right);
    }

    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        memset(t, -1, sizeof(t));

        return solve(grid, 0, 0);
    }
};