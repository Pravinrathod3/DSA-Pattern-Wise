#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  
    int recurse(int i, vector<int>& nums, vector<int>& dp){

        if(i >= nums.size()){
            return 0;
        }

        if(dp[i] != -1) return dp[i];

        int first = recurse(i+2, nums, dp) + nums[i];
        int sec = recurse(i+3, nums, dp) + nums[i];

        return dp[i] = max(first, sec);


    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        if(n < 2){
            return nums[0];
        }

        return max(recurse(0, nums, dp), recurse(1, nums, dp));
    }
};


int main(){
    Solution sol;
    vector<int> nums = {2,7,9,3,1};
    cout << sol.rob(nums) << endl; // Output: 12
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)