class Solution {
public:
    //memoization
    int t[2501][2501];
    int n;
    int solve(int idx, int prev, vector<int>& nums){
        if(idx>=n) return 0;

        if(prev!=-1 && t[idx][prev]!=-1){
            return t[idx][prev];
        }

        //take
        int take=0;
        if(prev==-1 || nums[prev]<nums[idx]){
            take=1+solve(idx+1,idx,nums);
        }
        //skip
        int skip = solve(idx+1,prev,nums);

        if(prev!=-1){
            t[idx][prev]=max(skip,take);
        }

        return max(skip,take);
    }
    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        memset(t,-1,sizeof(t));

        return solve(0,-1,nums);
    }
};