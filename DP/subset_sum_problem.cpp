#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    bool findsubset(int node, vector<int>& arr, int target, int sum, vector<vector<int>>& dp){
        
        if(sum == target){
            return true;
        }
        else if(sum > target){
            return false;
        }
        if(node == arr.size()){
            return false;
        }
        
        if(dp[node][sum] != -1) return dp[node][sum];
        
        
        if(findsubset(node+1, arr, target, sum, dp)) return dp[node][sum] = true;

        if(findsubset(node+1, arr, target, sum + arr[node], dp)) return dp[node][sum] = true;
        
        return dp[node][sum] = false;
    }
  
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        
        int res = 0;
        
        vector<vector<int>> dp(n, vector<int> (sum+1, -1));
        
        
        if(findsubset(0, arr, sum, res, dp)){
            return true;
        }
        
        
        return false;
        
    }
};

int main(){
    Solution sol;
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    if(sol.isSubsetSum(arr, sum)){
        cout << "Found a subset with given sum" << endl;
    } else {
        cout << "No subset with given sum" << endl;
    }
    return 0;
}