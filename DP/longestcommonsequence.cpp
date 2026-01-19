class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n, vector<int> (m, 0));

        dp[0][0] = (text1[0] == text2[0]);    // Initialize first cell of dp table

        for(int j=1; j<m; j++){              // Initialize first row of dp table because it has only one string to compare with 
            if(text1[0] == text2[j]){
                dp[0][j] = 1;               // If there is a match, set to 1 because only one character can be matched
            }
            else{
                dp[0][j] = dp[0][j-1];    // Else take the previous value because the longest common subsequence will be same as previous
            }
        }

        for(int i=1; i<n; i++){
            if(text1[i] == text2[0]){          // Initialize first column of dp table because it has only one string to compare with
                dp[i][0] = 1;
            }
            else{
                dp[i][0] = dp[i-1][0];     // Else take the previous value because the longest common subsequence will be same as previous 
            }
        }

        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){

                if(text1[i] == text2[j]){         // If there is a match, add 1 to the diagonal value
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    int left = dp[i-1][j];      // If there is no match, take the maximum of top values

                    int right = dp[i][j-1];     // If there is no match, take the maximum of right values
                      

                    dp[i][j] = max(left, right);
                }

            }
        }

        return dp[n-1][m-1];
    }
};