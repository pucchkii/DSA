class Solution {
public:
    int n;
    int t[1001][1001];
    static bool myFunction(string &word1, string &word2){
        return word1.length()<word2.length();
    }

    bool isPred(string& prev, string& curr){
        int n=prev.size();
        int m=curr.size();

        if((m-n)!=1 || n>m) return false;
        int i=0, j=0;

        while(i<n && j<m){
            if(prev[i]==curr[j]){
                i++;
            }
            j++;
        }
        return i==n;
    }

    int LIS(vector<string>& words, int idx, int prev){
        if(idx==n){
            return 0;
        }
        if(prev!=-1 && t[prev][idx]!=-1){
            return t[prev][idx];
        }
        int take=0,skip=0;
        if(prev==-1 ||isPred(words[prev],words[idx])){
            take=1+LIS(words,idx+1,idx);
        }
        skip=LIS(words,idx+1,prev);
        if(prev!=-1){
            t[prev][idx]=max(take,skip);
        }

        return max(take,skip);
    }
    int longestStrChain(vector<string>& words) {
        n=words.size();
        memset(t,-1,sizeof(t));
        sort(begin(words),end(words),myFunction);
        return LIS(words,0,-1);
    }
};