class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int> st;
        for(int num : nums){
            st.insert(num);
        }
        int val=k;
        while(true){
            if(!st.count(val)){
                return val;
                break;
            }
            val+=k;
        }
        return -1;
        
    }
};