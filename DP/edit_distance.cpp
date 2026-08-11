class Solution {
public:

    int solve(int i, int j, string& word1, string& word2, vector<vector<int>>& dp){
        if(i < 0) return j+1;
        if(j < 0) return i+1;

        if(dp[i][j] != -1) return dp[i][j];

        if(word1[i] == word2[j]){
            return dp[i][j] = solve(i-1, j-1, word1, word2, dp);
        }
        else{
            return dp[i][j] = 1 + min({solve(i, j-1, word1, word2, dp), solve(i-1, j, word1, word2, dp), solve(i-1, j-1, word1, word2, dp)});
        }
    }

    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        if(m == 0) return n;
        if(n == 0) return m;

        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));

        for(int i=0; i<=m; i++) dp[i][0] = i;
        for(int i=0; i<=n; i++) dp[0][i] = i;

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1 + min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});
                }
            }
        }

        return dp[m][n];
    }
};

//tabulation for word1="horse" and word2="ros"

/*
    
    ""  r  o  s         
    "  0  1  2  3"
    "h  1  1  2  3"
    "o  2  2  1  2"
    "r  3  2  2  2"
    "s  4  3  3  2"
    "e  5  4  4  3"

*/