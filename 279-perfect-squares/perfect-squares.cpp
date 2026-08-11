class Solution {
public:
    int t[101][10001];

    int solve(int i, int n) {

        if (n == 0) {
            return 0;
        }

        if (i * i > n) {
            return 1e9;
        }

        if (t[i][n] != -1) {
            return t[i][n];
        }

        int take = 1e9;
        int skip = 1e9;

        take = 1 + solve(i, n - i * i);

        skip = solve(i + 1, n);

        return t[i][n] = min(take, skip);
    }

    int numSquares(int n) {
        memset(t, -1, sizeof(t));

        return solve(1, n);
    }
};