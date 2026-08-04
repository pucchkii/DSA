class Solution {
public:
    int minCut(string s) {
        int n=s.length();

        //blue print code use
        vector<vector<bool>> t(n,vector<bool>(n,false));
        //t[i][j] =ture/false (s[i...j] substring is a palindorme or not)

        //length =1 substring
        for(int i=0 ; i<n ; i++){
            t[i][i]=true; // s[i...i] is always a palindorme
        }

        // Lenght>=2
        for(int L=2 ; L<=n ; L++){
            for(int i=0 ; i+L-1<n ; i++){
                int j=i+L-1;
                if(L==2){
                    t[i][j]=(s[i]==s[j]);
                }else{
                    t[i][j]=((s[i]==s[j]) && t[i+1][j-1]);
                }
            }
        }
        vector<int> dp(n,INT_MAX);
        // dp[i]=min cuts req to cut a string s[0...i] into palindorme
        for(int i=0 ; i<n ; i++){
            if(t[0][i]==true){// s[0...i] is a plaindorme
                dp[i]=0; // no cuts required
            }else{
                for(int k=0 ; k<i ; k++){
                    if(t[k+1][i]==true && 1+dp[k]<dp[i]){
                        dp[i]=1+dp[k];
                    }
                }   
            }
        }
        return dp[n-1];// s[0...n-1] entire string min cuts required to split it into plaindormes only
    }
};