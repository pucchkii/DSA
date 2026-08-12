class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[256];
        fill(hash,hash+256,-1); // char, latest_occurence
        int l=0, r=0;
        int maxLen=0, len=0;

        while(r < s.length()){
            if(hash[s[r]]!=-1){
                if(hash[s[r]]>=l){
                    l=hash[s[r]]+1;
                }
            }
            len=r-l+1;
            maxLen=max(maxLen,len);
            hash[s[r]]=r;
            r++;
        }
        return maxLen;
        
    }
};