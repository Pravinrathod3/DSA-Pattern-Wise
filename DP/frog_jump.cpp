#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    int recurse(int n, vector<int>& height, vector<int>& dp){
        if(n <= 0){
            return 0;           // Base case: If at the first stone, no cost incurred
        }
        
        if(dp[n] != -1) return dp[n];
        
        int left = recurse(n-1, height, dp) + abs(height[n-1] - height[n]);   // Jumping from n-1 to n
        
        int right = INT_MAX;
        if(n > 1){
          right = recurse(n-2, height, dp) + abs(height[n-2] - height[n]);      // Jumping from n-2 to n
        }
        
        
        return dp[n] = min(left, right);   // Storing the result in dp array and returning the minimum cost
        
        
    }
  
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n, -1);          // Memoization array
    
        
        return recurse(n-1, height, dp);
    }
};

int main(){
    Solution sol;
    vector<int> height = {10, 30, 40, 20};
    int result = sol.minCost(height);  
    cout << result << endl;
    return 0;
}

// Time Complexity: O(n) where n is the number of stones.
// Space Complexity: O(n) for the dp array used for memoization.