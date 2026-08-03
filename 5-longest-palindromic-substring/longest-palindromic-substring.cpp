class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();

        vector<vector<bool>> t(n,vector<bool>(n));
        // state: t[i][j] = true ---> if s[i:j] is plaindrome, false if s[i:j] is not a plaindorme

        int maxL=0;
        int idx=0;

        //t[0][0]=true, t[1][1]=true and so on
        for(int i=0 ; i<n ; i++){
            t[i][i]=true;
            maxL=1;
        }

        for(int L=2 ; L<=n ; L++){
            for(int i=0 ; i+L-1<n  ; i++){
                int j = i+L-1;

                if(L==2 && s[i]==s[j] ){
                    t[i][j]=true;
                    maxL=2;
                    idx=i;
                }
                else if(s[i]==s[j] && t[i+1][j-1]){
                    t[i][j]=true;

                    if(j-i+1>maxL){
                        maxL=j-i+1;
                        idx=i;
                    }
                }else{
                    t[i][j]=false;
                }
                
            }
        }
        return s.substr(idx,maxL);
    }
};