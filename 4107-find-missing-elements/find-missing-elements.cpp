class Solution {
public:
    int n;
    bool notPresent(int k, vector<int>& nums){
        for(int i=0 ; i<n ; i++){
            if(nums[i]==k){
                return false;
            }
        }
        return true;
    }
    vector<int> findMissingElements(vector<int>& nums) {
        int mini=*min_element(nums.begin(),nums.end());
        int maxi=*max_element(nums.begin(),nums.end());
        n=nums.size();
        vector<int> ans;

        int l=maxi-mini+1;

        for(int i=mini ; i<maxi ; i++){
            if(notPresent(i,nums)){
                ans.push_back(i);
            }  
        }
        return ans;
    }
};