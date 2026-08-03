    // class Solution {
    // public:
    //     // memoization
    //     int t[1001][1001];
    //     int n;
    //     int check(string s, int i, int j){
    //         if(i>j) return true;
    //         if(t[i][j]!=-1){
    //             return t[i][j];
    //         }
    //         if(s[i]==s[j]){
    //             return t[i][j]=check(s,i+1,j-1);
    //         }else{
    //             return t[i][j]=false;
    //         }
    //     }
    //     int countSubstrings(string s) {
    //         memset(t,-1,sizeof(t));
    //         n=s.length();
    //         int cnt=0;
    //         for(int i=0 ; i<n ; i++){
    //             for(int j=i ; j<n ; j++){
    //                 if(check(s,i,j)){
    //                     cnt++;
    //                 }
    //             }
    //         }
    //         return cnt;
    //     }
    // };

    // using bottom up approach
class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        vector<vector<bool>> t(n,vector<bool>(n,false));
        //STATE : t[i][j] = True : s[i:j] is a palindromic substring where i and j are inclusive indices

        int cnt=0;

        for(int L=1 ; L<=n ; L++){

            for(int i= 0 ; i+L-1 < n ; i++){
                int j = i + L - 1;

                if(i==j) 
                    t[i][j]=true;

                else if(i+1==j){
                    t[i][j]=(s[i]==s[j]);
                }
                else{
                    t[i][j]=((s[i]==s[j]) && t[i+1][j-1]);
                }

                if(t[i][j]==true){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};