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

//print lcs



string findLCS(int n, int m,string &text1, string &text2){
        
        vector<vector<int>> dp(n, vector<int> (m, 0));

        dp[0][0] = (text1[0] == text2[0]);

        for(int j=1; j<m; j++){
            if(text1[0] == text2[j]){
                dp[0][j] = 1;
            }
            else{
                dp[0][j] = dp[0][j-1];
            }
        }

        for(int i=1; i<n; i++){
            if(text1[i] == text2[0]){
                dp[i][0] = 1;
            }
            else{
                dp[i][0] = dp[i-1][0];
            }
        }

        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){

                if(text1[i] == text2[j]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    int left = dp[i-1][j];

                    int right = dp[i][j-1];
                    

                    dp[i][j] = max(left, right);
                }

            }
        }

        int len = dp[n-1][m-1];   // Length of longest common subsequence
        string ans;               // To store the longest common subsequence

        for(int i=0; i<len; i++){
            ans += '$';          // Initialize the string with dummy characters
        }

        int index = len-1;
        int i=n-1, j=m-1;

        while(i >= 0 && j >= 0){
            if(text1[i] == text2[j]){    // If there is a match, add the character to the answer
                ans[index] = text1[i];
                index--;                 // Move to the previous index
                i--;
                j--;
            }
            else if(i == 0){         // If we reach the first row, move left
               j--;
            }
            else if(j == 0){           // If we reach the first column, move up
                i--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){  // If the top value is greater, move up 
                i--;
            }
            else{                             // If the left value is greater, move left
                j--;
            }
        }


       return ans;          // Return the longest common subsequence



}