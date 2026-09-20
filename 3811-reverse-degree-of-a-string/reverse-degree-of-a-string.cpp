class Solution {
public:
    int reverseDegree(string s) {
        int sum=0;
        int i=1;
        for(char s1:s){
            int prod=i*(26-(s1-'a'));
            sum+=prod;
            i++;
        }
        return sum;
        
    }
};