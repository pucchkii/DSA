class Solution {
public:
    int n;
    // creating solve function
    void solve(string& s, int i, vector<vector<string>> & result, vector<string>& partition, vector<vector<int>> &t){
        if(i==n){
            result.push_back(partition);
            return ;
        }

        for(int j=i ; j<n ; j++){
            if(t[i][j]){
                partition.push_back(s.substr(i,j-i+1));
                solve(s,j+1,result,partition,t);
                partition.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        // using khandani palindrome bottom up approach template
        n=s.length();

        vector<vector<int>> t(n,vector<int>(n));
        for(int i=0 ; i<n ; i++){
            t[i][i]=true;
        }
        for(int L=2 ; L<=n ; L++){
            for(int i=0 ; i+L-1 <n ; i++){
                int j=i+L-1;
                if(s[i]==s[j]){
                    if(L==2){
                        t[i][j]=true;
                    }else{
                        t[i][j]=t[i+1][j-1];
                    }
                }
            }
        }// create my t[i][j]
        //state definition t[i][j]--->True : s[i....j] is a plaindrome
                        // t[i][j]--->False: s[i....j] is not a palindorme

        vector<vector<string>> result;
        vector<string> partition;

        solve(s,0,result,partition,t);
        return result;

        
    }
};