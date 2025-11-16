#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  
    int frecurse(int i, vector<int>& nums, vector<int>& dp){

        if(i >= nums.size()-1){
            return 0;
        }

        if(dp[i] != -1) return dp[i];

        int first = frecurse(i+2, nums, dp) + nums[i];
        int sec = frecurse(i+3, nums, dp) + nums[i];

        return dp[i] = max(first, sec);


    }

    int lrecurse(int i, vector<int>& nums, vector<int>& dp){

        if(i >= nums.size()){
            return 0;
        }

        if(dp[i] != -1) return dp[i];

        int first = lrecurse(i+2, nums, dp) + nums[i];
        int sec = lrecurse(i+3, nums, dp) + nums[i];

        return dp[i] = max(first, sec);


    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> fdp(n, -1);
        vector<int> ldp(n, -1);

        if(n < 2){
            return nums[0];
        }

        int first = max(frecurse(0, nums, fdp), frecurse(1, nums, fdp));
        int last = max(lrecurse(1, nums, ldp), lrecurse(2, nums, ldp));

        return max(first, last);
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2,7,9,3,1};
    cout << sol.rob(nums) << endl; // Output: 11
    return 0;
}