class Solution {
public:
    int n;
    int t[1001][1001];

    int LIS(vector<vector<int>>& pairs , int idx, int prev){
        if(idx==n){
            return 0;
        }

        if(prev!=-1 && t[idx][prev]!=-1){
            return t[idx][prev];
        }

        //take 
        int take=0;
        if(prev==-1 || pairs[idx][0]>pairs[prev][1]){
            take=1+LIS(pairs,idx+1,idx);
        }
        //skip
        int skip=LIS(pairs,idx+1,prev);

        if(prev!=-1){
            t[idx][prev]=max(skip,take);
        }

        return max(skip,take);
    }

    //using LIS

    int findLongestChain(vector<vector<int>>& pairs) {
        n=pairs.size();
        memset(t,-1,sizeof(t));
        sort(pairs.begin(),pairs.end());
        return LIS(pairs,0,-1);
    }
};