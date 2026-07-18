class Solution {
public:
    int findLongestChain(vector<vector<int>>& nums) {
        int n=nums.size();

        sort(begin(nums),end(nums));
        vector<int> t(n+1,1);

        int maxLIS=1;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<i ; j++){
                if(nums[j][1]<nums[i][0]){
                    t[i]=max(t[i],t[j]+1);
                }
                maxLIS=max(maxLIS,t[i]);
            }
        }
        return maxLIS;
    }
};