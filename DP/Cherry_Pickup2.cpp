#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int robot(int row1, int col1, int col2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
        int m = grid.size();
        int n = grid[0].size();

        if(row1 >= m || col1 >= n || col1 < 0){
            return 0;
        }

        if(row1 >= m || col2 >= n || col2 < 0){
            return 0;
        }

        if(dp[row1][col1][col2] != -1){
            return dp[row1][col1][col2];
        }


        int sum = 0;
        int path[3] = {-1, 0, 1};

        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(col1 == col2){
                   sum = max(robot(row1+1, col1+path[i], col2+path[j], grid, dp) + grid[row1][col1], sum);
                }
                else{
                   sum = max(robot(row1+1, col1+path[i], col2+path[j], grid, dp) + grid[row1][col1] + grid[row1][col2], sum);
                }
                
            }
        }

        return dp[row1][col1][col2] = sum;

    }

    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (n, -1)));
        
        return robot(0, 0, n-1, grid, dp);
    }
};

int main(){
    Solution sol;
    vector<vector<int>> grid = {
        {3,1,1},
        {2,5,1},
        {1,5,5},
        {2,1,1}
    };
    int result = sol.cherryPickup(grid);
    cout << result << endl;
    return 0;

}

// Time Complexity: O(m * n * n) where m is the number of rows and n is the number of columns in the grid
// Space Complexity: O(m * n * n) for the dp array used for memoization