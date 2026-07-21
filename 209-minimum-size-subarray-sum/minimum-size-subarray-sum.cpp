class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int windowSum=0;
        int n=nums.size();

        int l=0, r=0;
        int ans=INT_MAX;
        while(r<n){
            windowSum+=nums[r];

            while(windowSum>=target){
                windowSum-=nums[l];
                ans=min(ans,r-l+1);
                l++;
            }
            r++;
        }
            return ans==INT_MAX ? 0 : ans;
    }

};