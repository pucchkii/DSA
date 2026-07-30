class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();

        //creating vector dp[n+1][m+1];
        vector<vector<int>> t(n+1,vector<int>(m+1));

        // first row and first col is 0.
        for(int i=0 ; i<n+1 ; i++){
            t[i][0]=0;
        }
        for(int i=0 ; i<m+1 ; i++){
            t[0][i]=0;
        }
        for(int i=1 ; i<n+1 ; i++){
            for(int j=1 ; j<m+1 ; j++){
                if(s1[i-1]==s2[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }else{
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        //created t array now finding lcs
        string lcs="";
        int i=n , j=m;
        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){
                lcs.push_back(s1[i-1]);
                i--;
                j--;
            }else{
                if(t[i-1][j]>t[i][j-1]){
                    i--;
                }else{
                    j--;
                }
            }
        }
        reverse(begin(lcs),end(lcs));
        cout<<lcs;
        return t[n][m];
    }
};