class Solution {
public:
    int M, N, K;
    int mod=1e9+7;
    //memoization
    int t[51][51][101]; //t[n][k][m];
    int solve(int idx, int searchCost, int maxSoFar){
        // base case
        if(idx==N){
            if(searchCost==K){
                return 1;
            }
            return 0;
        }
        if(t[idx][searchCost][maxSoFar]!=-1){
            return t[idx][searchCost][maxSoFar];
        }
        int result=0;
        for(int i=1 ; i<=M ; i++){
            if(i>maxSoFar){
                result=(result+solve(idx+1,searchCost+1,i))%mod;
            }else{
                result=(result+solve(idx+1,searchCost,maxSoFar))%mod;
            }
        }
        return t[idx][searchCost][maxSoFar]=result%mod;

    }
    int numOfArrays(int n, int m, int k) {
        N=n;
        M=m;
        K=k;
        memset(t,-1,sizeof(t));
        return solve(0,0,0);
        
    }
};