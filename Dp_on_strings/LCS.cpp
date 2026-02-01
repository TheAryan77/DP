//Memoization
class Solution {
public:
    int t[1001][1001];
    int solve(string s1,string s2,int i,int j){
        if(i>=s1.length() || j>=s2.length()){
            return 0;
        }
        if(t[i][j] != -1){
            return t[i][j];
        }
        if(s1[i] == s2[j]){
            return t[i][j] =  1 + solve(s1,s2,i+1,j+1);
        }
        else{
            return t[i][j] = max(solve(s1,s2,i+1,j),solve(s1,s2,i,j+1));
        }
    }
    int longestCommonSubsequence(string s1, string s2) {
        memset(t,-1,sizeof(t));
        return solve(s1,s2,0,0);
    }
};
//Tabulation
class Solution {
public:
    int findLength(string s1, string s2 ) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i = 0;i<n;i++){
            dp[i][0] = 0;
        }
        for(int j = 0;j<n;j++){
            dp[0][j] = 0;
        }
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(nums1[i-1] == num2[i-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};