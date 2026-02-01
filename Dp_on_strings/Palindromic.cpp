class Solution {
public:
    int solve(string s1,string s2,int i,int j,vector<vector<int>> &dp){
        if(i >= s1.size() || j >= s2.size()){
            return 0;
        }
        if(dp[i][j] != 0){
            return dp[i][j];
        }
        if(s1[i]==s2[j]){
            return dp[i][j] = 1 + solve(s1,s2,i+1,j+1,dp);
        }
        else{
            return dp[i][j] = max(solve(s1,s2,i+1,j,dp),solve(s1,s2,i,j+1,dp));
        }

    }
    //Both codes , memoisation and tabulisation , mem will fail cause of space,tab will work...(commented)
    int longestPalindromeSubseq(string s) {
        string s2 = s;
        string s1 = s;
        reverse(s1.begin(),s1.end());
        int n = s1.length();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        // for(int i = 1;i<=n;i++){
        //     for(int j = 1;j<=n;j++){
        //         if(s1[i-1] == s2[j-1]){
        //             dp[i][j] = 1 + dp[i-1][j-1];
        //         }
        //         else{
        //             dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        //         }
        //     }
        // }
        // return dp[n][n];
        return solve(s1,s2,0,0,dp);
    }
};