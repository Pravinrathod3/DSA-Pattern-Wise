#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
   int recurse(int i, int j, vector<vector<int>>& arr, vector<vector<int>>& dp){
       if(i == arr.size()){
           return 0;
       }
       
       if(dp[i][j] != -1) return dp[i][j];
       
       int maxi = 0;
       
       for(int num = 0; num<3; num++){
           if(num != j){
               maxi = max(recurse(i+1, num, arr, dp) + arr[i][j], maxi);
           }
       }
       
       
       return dp[i][j] = maxi;
   }
  
    int maximumPoints(vector<vector<int>>& arr) {
       int n = arr.size();
       
       int maxi = 0;
       vector<vector<int>> dp(n, vector<int> (3, -1));
       
       
       for(int i=0; i<3; i++){
           maxi = max(recurse(0, i, arr, dp), maxi);
       }
      
        return maxi;
       
    }
};

int main(){
    Solution sol;
    vector<vector<int>> arr = {{1,2,5},{3,1,1},{3,3,3}};
    cout << sol.maximumPoints(arr) << endl; // Output: 11
    return 0;
}

// Time Complexity: O(N*3*2) where N is the number of days. For each day, we have 3 tasks and for each task, we check 2 other tasks.
// Space Complexity: O(N*3) for the dp array used for memoization.