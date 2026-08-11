class Solution {
public:
    int n;
    vector<vector<int>> t;
    int solve(int x, int amount,vector<int>& coins){
        if(amount==0){
            return 0;
        }
        if(amount<0 || x<0){
            return 1e9;
        }
        if(t[x][amount]!=-1){
            return t[x][amount];
        }
        int take=1e9;
        int skip=1e9;
        if(amount-coins[x]>=0){
            take=1+solve(x,amount-coins[x],coins);
        }
        skip=solve(x-1,amount,coins);

        return t[x][amount]=min(skip,take);
    }
    int coinChange(vector<int>& coins, int amount) {
        n=coins.size();
        t.assign(n,vector<int>(amount+1,-1));
        int ans=solve(n-1,amount,coins);
        return ans==1e9 ? -1 : ans;
    }
};