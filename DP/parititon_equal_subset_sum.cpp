//memoization

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

   bool partition(int node, vector<int>& nums, int total, int sum, vector<vector<int>>& dp){
    if(node == nums.size()){
        return (sum == (total-sum));
    }

    if(dp[node][sum] != -1) return dp[node][sum];

    bool left = partition(node+1, nums, total, sum, dp);
    if(left) return  dp[node][sum] = true;
    bool right = partition(node+1, nums, total, sum+nums[node], dp);
    if(right) return  dp[node][sum] = true;

    return dp[node][sum] = false;
   }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(auto it: nums){
            total += it;
        }

        vector<vector<int>> dp(n, vector<int> (total+1, -1));

        return partition(0, nums, total, 0, dp);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 5, 11, 5};
    if(sol.canPartition(nums)) {
        cout << "Can partition into equal subset sum." << endl;
    } else {
        cout << "Cannot partition into equal subset sum." << endl;
    }
    return 0;
}

//tabulation

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(auto it: nums){
            total += it;
        }

        if(total % 2 != 0) return false;

        int target = total / 2;

        vector<vector<bool>> dp(n+1, vector<bool> (target+1, false));

        for(int i=0; i<=n; i++){
            dp[i][0] = true;
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=target; j++){
                if(nums[i-1] <= j){
                    dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i-1]];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][target];
    }
};


int main() {
    Solution sol;
    vector<int> nums = {1, 5, 11, 5};
    if(sol.canPartition(nums)) {
        cout << "Can partition into equal subset sum." << endl;
    } else {
        cout << "Cannot partition into equal subset sum." << endl;
    }
    return 0;
}
