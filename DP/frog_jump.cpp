#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    int recurse(int n, vector<int>& height, vector<int>& dp){
        if(n <= 0){
            return 0;
        }
        
        if(dp[n] != -1) return dp[n];
        
        int left = recurse(n-1, height, dp) + abs(height[n-1] - height[n]);
        
        int right = INT_MAX;
        if(n > 1){
          right = recurse(n-2, height, dp) + abs(height[n-2] - height[n]);
        }
        
        
        return dp[n] = min(left, right);
        
        
    }
  
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n, -1);
    
        
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