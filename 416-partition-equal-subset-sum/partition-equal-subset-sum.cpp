class Solution {
public:
    int n;
    int t[201][10001];
    bool solve(int sum, vector<int>& nums, int n){
        if(sum==0){
            return true;
        }
        if(n==0){
            return false;
        } 
        if(t[n][sum]!=-1){
            return t[n][sum];
        }
        bool skip=solve(sum,nums,n-1);
        bool take=false;
        if(sum>=nums[n-1]){
            take=solve(sum-nums[n-1],nums,n-1);
        }
        return t[n][sum]=take||skip;
    }

    bool canPartition(vector<int>& nums) {
        n=nums.size();
        int sum=0;
        for(int x : nums){
            sum+=x;
        }

        if(sum%2!=0) return false;
        sum=sum/2;
        memset(t,-1,sizeof(t));

        return solve(sum,nums,n);
        
    }
};