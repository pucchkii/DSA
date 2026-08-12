class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l=0, r=0;
        map<int,int> mp;
        int maxLen=0;
        int len=0;
        while(r<nums.size()){
            if(mp[nums[r]]<k){
                mp[nums[r]]++;
                r++;
                len++;
                maxLen=max(maxLen,len);
            }else if(mp[nums[r]]==k){
                while(mp[nums[r]]>=k){
                    mp[nums[l]]--;
                    l++;
                    len--;
                }
            }
        }
        return maxLen;
    }
};