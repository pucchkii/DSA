class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();

        vector<vector<int>> t(n+1,vector<int>(m+1));

        for(int row=0 ; row<n+1 ; row++){
            t[row][0]=0;
        }
        for(int col=0 ; col<m+1 ; col++){
            t[0][col]=0;
        }

        for(int i=1 ; i<n+1; i++){
            for(int j=1 ; j<m+1 ; j++){
                if(text1[i-1]==text2[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }else{
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        return t[n][m];
        
    }
};