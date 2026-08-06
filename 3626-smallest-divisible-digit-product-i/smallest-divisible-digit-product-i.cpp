class Solution {
public:
    bool solve(int n ,int t){
        int prod=1;
        while(n>0){
            prod*=n%10;
            n/=10;
        }
        return prod%t==0 ;
    }
    int smallestNumber(int n, int t) {
        while(true){
            if(solve(n,t)){
                return n;
                break;
            }else{
                n++;
            }
        }   
        
    }
};