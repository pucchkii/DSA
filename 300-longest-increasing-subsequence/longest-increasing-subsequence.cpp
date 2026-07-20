class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // using patience sort
        int n=nums.size();
        vector<int> sorted;

        for(int i=0 ; i<n ; i++){
            auto it = lower_bound(begin(sorted),end(sorted),nums[i]);
            if(it==sorted.end()){
                sorted.push_back(nums[i]);
            }else{
                *it=nums[i];
            }
        }
        return sorted.size();
        
    }
};