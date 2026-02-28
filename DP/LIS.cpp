class Solution {
public:

    int sequence(int i, int node, vector<int>& nums, vector<vector<int>>& dp, int offset){
        if(i == nums.size()) return 0;

        if(dp[i][offset + node] != -1) return dp[i][offset + node];

        if(node == -1 || nums[node] < nums[i]){
            return dp[i][offset + node] = max( (1 + sequence(i+1, i, nums, dp, offset)), sequence(i+1, node, nums, dp, offset) );
        }
        else{
            return dp[i][offset + node] = sequence(i+1, node, nums, dp, offset);
        }
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

         for(int i=n-1; i>=0; i--){
            for(int j=n-1; j>=-1; j--){  //we iterate through the array in reverse order and for each index, we iterate through the previous indices in reverse order as well, starting from -1 to handle the case when there is no previous index (which means we are at the start of the array)

                int nottake = dp[i+1][j+1];      //not take the current element, so the length of the longest increasing subsequence remains the same as the next index with the same previous index

                int take = 0;

                if(j == -1 || nums[j] < nums[i]){  //if the previous index is -1 (which means we are at the start) or the current element is greater than the previous element, then we can take the current element and add 1 to the length of the longest increasing subsequence from the next index with the current index as the new previous index
                   take = 1 + dp[i+1][i+1];        //we add 1 to the length of the longest increasing subsequence from the next index with the current index as the new previous index, which is represented by i+1 in the dp array because we have shifted the indices by 1 to handle the case when j is -1
                }
                

                dp[i][j+1] = max(take, nottake);   //we take the maximum of the two choices, which is either taking the current element or not taking it, and store it in the dp array at the current index and the previous index + 1 (to handle the case when j is -1)
            }
        }

        return dp[0][0];
    }
};