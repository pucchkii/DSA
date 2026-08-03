class Solution {
public:
    int n,m;
    int t[501][501]; // i and n
    int solve(const string &s1, const string &s2, int i, int j){
        if(i>=n) return m-j;
        if(j>=m) return n-i;

        if(t[i][j]!=-1){
            return t[i][j];
        }

        // creating futrue options
        if(s1[i]==s2[j]){
            return t[i][j]=solve(s1,s2,i+1,j+1);
        }
        int option_Replace = 1 + solve(s1,s2,i+1,j+1);
        int option_insert = 1 + solve(s1,s2,i,j+1);
        int option_delete = 1 + solve(s1,s2,i+1,j);
            
        return  t[i][j]=min({option_Replace, option_insert, option_delete});
    


    }
    int minDistance(string s1, string s2) {
        memset(t,-1,sizeof(t));
        n=s1.length();
        m=s2.length();
        return solve(s1,s2,0,0); // [word1 , word2 , idx i of word1 , idx j of word2 , initally both starting at zero]
    }
};