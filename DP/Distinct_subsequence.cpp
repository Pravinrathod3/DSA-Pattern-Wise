class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

        for(int j=0; j<=n; j++) dp[j][0] = 1;
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){               //sting 2 all characters should be present in string 1
                if(text1[i-1] == text2[j-1]){      //if string matches then take value from diagonal + value from top
                   dp[i][j] =  (long long)dp[i-1][j-1] + (long long)dp[i-1][j];
                }
                else{
                   dp[i][j] = dp[i-1][j];       //if not matches then take value from top
                }
            }
        }
        
        return dp[n][m];
    }

    int numDistinct(string s, string t) {
        return longestCommonSubsequence(s, t);
    }
};