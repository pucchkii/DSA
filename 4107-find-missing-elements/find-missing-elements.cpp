class Solution {
public:
    int n;
    int t[101];
    vector<int> findMissingElements(vector<int>& nums) {
        int mini=*min_element(nums.begin(),nums.end());
        int maxi=*max_element(nums.begin(),nums.end());
        n=nums.size();
        vector<int> ans;
        memset(t,false,sizeof(t));
        for(int x : nums){
            t[x]=true;
        }

        int l=maxi-mini+1;

        for(int i=mini ; i<=maxi ; i++){
            if(!t[i]){
                ans.push_back(i);
            }  
        }
        return ans;
    }
};