class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> t(n+1,0);

        if(n==1){
            return nums[0];
        }
        t[0]=0;
        t[1]=nums[0];

        // case 1:(take 1st house hence, skip the last house)
        for(int i=1 ; i<=n-1 ; i++){
            int skip=t[i-1];
            int steal=nums[i-1]+(i-2>=0 ? t[i-2] : 0);
            t[i]=max(skip,steal);
        }
        int result1=t[n-1];

        // case 2:(take 2nd house hence, taking the last house)
        t.clear();
        t[0]=0;
        t[1]=0;
        for(int i=2 ; i<=n ; i++){
            int skip=t[i-1];
            int steal=nums[i-1]+(i-2>=0 ? t[i-2] : 0);
            t[i]=max(skip,steal);
        }
        int result2=t[n];

        return max(result1,result2);


    }
};