class Solution {
public:
    int n,m;
    int t[501][501]; // i and j : state definition ---> number of operations required for string s1 of len i and string s2 of len j to be same or equal
    int solve(const string &s1, const string &s2, int n, int m){
            // if(i>=n) return m-j;
            // if(j>=m) return n-i;

        if(n==0 || m==0) return m+n;

        if(t[n][m]!=-1){
            return t[n][m];
        }

        // creating futrue options
        if(s1[n-1]==s2[m-1]){
            return t[n][m]=solve(s1,s2,n-1,m-1);
        }
        int option_Replace = 1 + solve(s1,s2,n-1,m-1);
        int option_insert = 1 + solve(s1,s2,n,m-1);
        int option_delete = 1 + solve(s1,s2,n-1,m);
            
        return  t[n][m]=min({option_Replace, option_insert, option_delete});
    


    }
    int minDistance(string s1, string s2) {
        memset(t,-1,sizeof(t));
        n=s1.length();
        m=s2.length();
        return solve(s1,s2,n,m); // [word1 , word2 , idx i of word1 , idx j of word2 , initally both starting at zero]
    }
};