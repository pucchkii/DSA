class Solution {
public:
    typedef long long ll;
    int n;

    ll t[100001][2];

    ll solve(vector<int>& nums, int i, bool flag){
        if(i>=n){
            return 0;
        }
        if(t[i][flag]!=-1){
            return t[i][flag];
        }
        ll skip = solve(nums,i+1,flag);
        ll val = nums[i];
        if(flag==false){
            val=-val;
        }
        ll take = solve(nums,i+1,!flag) + val;

        return t[i][flag]=max(skip,take);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        n=nums.size();
        memset(t, -1,sizeof(t));

        return solve(nums,0,true);
    }
};