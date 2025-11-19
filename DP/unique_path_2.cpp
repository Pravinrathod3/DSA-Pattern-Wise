#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int> (n, 0));     // DP table

        if(obstacleGrid[0][0] || obstacleGrid[m-1][n-1]) return 0;   // If start or end is blocked

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                
                if(obstacleGrid[i][j] == 1){      // If cell is blocked 
                    dp[i][j] = 0;
                }
                else if(i == 0 && j == 0){        // First row and first column is 1
                    dp[i][j] = 1;       
                } 
                else{                             
                    int up = 0;
                    int left = 0;

                    if(i > 0) up = dp[i-1][j];   // From the cell above except first row
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
    vector<vector<int>> obstacleGrid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    cout << "Number of unique paths: " << sol.uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}