#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int left=0, right = 0;

        int ans = INT_MAX;
        int sum = 0;

        while(right < n){

            sum += nums[right];   // add the current element to the sum
            right++;             // move the right pointer to the right

            while(sum >= target){       // while the sum is greater than or equal to the target
                ans = min(ans, right-left);         // update the answer with the minimum length
                sum -= nums[left];              // subtract the leftmost element from the sum
                left++;               // move the left pointer to the right
            }
        }

        if(ans == INT_MAX) return 0;

        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;

    int result = sol.minSubArrayLen(target, nums);

    cout << "Minimum size subarray length: " << result << endl;

    return 0;
}