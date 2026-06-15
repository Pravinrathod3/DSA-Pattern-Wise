class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());  
        int n = nums.size();

        int ans = 0;
        long long sum = 0;
        int l = 0;   // left pointer of the sliding window

        for(int r=0; r<n; r++){  // right pointer of the sliding window
            sum += nums[r];            // add the current element to the sum of the window

            while(((long long)nums[r] * (r-l+1)) - sum > k){  // if the cost to make all elements in the window equal to nums[r] exceeds k
                sum -= nums[l];        // remove the leftmost element from the sum and move the left pointer to the right
                l++;
            }

            ans = max(ans, (r-l+1)); // update the maximum frequency found so far
        }

        return ans;
    }
};

