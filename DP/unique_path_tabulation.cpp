#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, 0));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                
                if(i == 0 && j == 0){   // First row and first column is 1
                    dp[i][j] = 1;       
                }
                else{
                    int up, left;

                    if(i > 0) up = dp[i-1][j];   // From the cell above axcept first row
                    if(j > 0) left = dp[i][j-1];  // From the cell to the left except first column
                    dp[i][j] = up+left;   // Total paths to (i, j)
                }

                
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