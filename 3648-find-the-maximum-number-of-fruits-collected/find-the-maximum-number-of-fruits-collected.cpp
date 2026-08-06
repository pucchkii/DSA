class Solution {
public:
    int n;

    vector<vector<int>> t;

    int child_3_Collect(int i, int j, vector<vector<int>>& fruits){
        // base case
        if(i>=n || i<0 || j>=n){
            return 0;
        }
        if(i==n-1 && j==n-1){
            return 0; // because (n-1,n-1) is already collected by child 1;
        }
        if(i==j || i<j){
            return 0;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }

        int upRight = fruits[i][j] + child_3_Collect(i-1 , j+1 , fruits);
        int right = fruits[i][j] + child_3_Collect(i , j+1 , fruits);
        int bottomRight = fruits[i][j] + child_3_Collect(i+1 , j+1 , fruits);

        return t[i][j]=max({upRight , right , bottomRight});
    }

    int child_2_Collect(int i, int j, vector<vector<int>>& fruits){
        // base case
        if(i>=n || j<0 || j>=n){
            return 0;
        }
        if(i==n-1 && j==n-1){
            return 0; // because (n-1,n-1) is already collected by child 1;
        }
        if(i==j || i>j){
            return 0;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }

        int bottomLeft = fruits[i][j] + child_2_Collect(i+1 , j-1 , fruits);
        int bottomDown = fruits[i][j] + child_2_Collect(i+1 , j , fruits);
        int bottomRight = fruits[i][j] + child_2_Collect(i+1 , j+1 , fruits);

        return t[i][j]=max({bottomLeft , bottomDown , bottomRight});
    }

    int child_1_Collect(vector<vector<int>>& fruits){
        int sum=0;
        for(int i=0 ; i<n ; i++){
            sum+=fruits[i][i];
        }
        return sum;

    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n=fruits.size();
        t.resize(n,vector<int>(n,-1));

        int c1 = child_1_Collect(fruits);

        int c2 = child_2_Collect(0 , n-1, fruits);

        int c3 = child_3_Collect(n-1 , 0 ,fruits);

        return c1+c2+c3;
    }
};