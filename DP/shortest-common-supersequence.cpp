class Solution {
public:

string findLCS(int n, int m, string &text1, string &text2){
        
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){

                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    int left = dp[i-1][j];

                    int right = dp[i][j-1];
                    

                    dp[i][j] = max(left, right);
                }

            }
        }

        string ans;               // To store the shortest common supersequence

        int i=n, j=m;

        while(i > 0 && j > 0){
            if(text1[i-1] == text2[j-1]){    // If there is a match, add the character to the answer
                ans.push_back(text1[i-1]);                // Move to the diagonal cell
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){  // If the top value is greater, move up 
                ans.push_back(text1[i-1]);      // Add the current character to the answer
                i--;
            }
            else{
                ans.push_back(text2[j-1]);      // If the left value is greater, move left
                j--;                           // Add the current character to the answer
            }
        }

        while(i > 0){                    // If there are remaining characters in text1, add them to the answer
           ans.push_back(text1[i-1]);
           i--;
        }
        while(j > 0){                     // If there are remaining characters in text2, add them to the answer
            ans.push_back(text2[j-1]);
            j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;

}



    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        return findLCS(n, m, str1, str2);
    }
};

// Time Complexity: O(n*m)
// Space Complexity: O(n*m)