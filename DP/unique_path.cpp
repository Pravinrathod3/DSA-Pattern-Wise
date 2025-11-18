#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int recurse(int i, int j, vector<vector<int>>& dp, int m, int n){
        if(i == m-1 && j == n-1){       // Reached destination
            return 1;
        }
        else if(i >= m || j >= n){      // Out of bounds
            return 0;
        }

        if(dp[i][j] != -1) return dp[i][j];    // Return already computed value

        int down = recurse(i+1, j, dp, m, n);   // Move down
        int right = recurse(i, j+1, dp, m, n);  // Move right

        return dp[i][j] = down+right;             // Store and return the total paths from (i, j)
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, -1)); //memoization table
        return recurse(0, 0, dp, m, n);
    }
};