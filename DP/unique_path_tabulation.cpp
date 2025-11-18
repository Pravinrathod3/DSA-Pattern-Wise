#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, 0));

        dp[0][0] = 1;  // Starting point

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int up, left;
                
                if(i == 0 || j == 0){   // First row or first column is 1
                    dp[i][j] = 1;       //if we are in first row or first column, there's only one way to reach any cell
                    continue;
                }
                else{
                    up = dp[i-1][j];   // From the cell above
                    left = dp[i][j-1];  // From the cell to the left
                }

                dp[i][j] = up+left;   // Total paths to (i, j)
                
            }
        }

        return dp[m-1][n-1];   // Return paths to bottom-right corner
    }
};

int main(){
    Solution sol;
    int m = 3, n = 7;
    cout << "Number of unique paths: " << sol.uniquePaths(m, n) << endl;
    return 0;
}

// Time Complexity: O(m*n)
// Space Complexity: O(m*n)