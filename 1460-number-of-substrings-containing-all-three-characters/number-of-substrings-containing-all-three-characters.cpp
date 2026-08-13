class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();

        int cnt=0;
        int hash[3] = {-1,-1,-1};

        for(int i=0 ; i<n ; i++){
            hash[s[i]-'a'] = i;
            if(hash[0]!=-1 && hash[1]!=-1 && hash[2]!=-1){
                cnt += min({hash[0],hash[1],hash[2]})+1;
            }
        }
        return cnt;
    }
};