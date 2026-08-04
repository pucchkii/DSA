class Solution {
public:
    int n;
    int t[101];
    vector<int> findMissingElements(vector<int>& nums) {
        int maxi=INT_MIN;
        int mini=INT_MAX;
        n=nums.size();
        vector<int> ans;
        memset(t,false,sizeof(t));
        for(int x : nums){
            maxi=max(maxi,x);
            mini=min(mini,x);
            t[x]=true;
        }


        for(int i=mini ; i<=maxi ; i++){
            if(!t[i]){
                ans.push_back(i);
            }  
        }
        return ans;
    }
};