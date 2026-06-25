class Solution {
public:

    int findsplit(vector<int>& nums, int maxsum){
        int n = nums.size();

        int split = 1;  //intialize split to 1 because we always have at least one subarray
        int sum = 0;  //initialize sum to 0 because we will keep track of the sum of the current subarray

        for(int i=0; i<n; i++){
            if(sum + nums[i] <= maxsum){  //if sum is less than split not required so we can add the current element to the current subarray
                sum += nums[i];
            }
            else{          //if sum is greater than maxsum then we need to split the array and start a new subarray with the current element
                split++;
                sum = nums[i];
            }
        }

        return split;
    }


    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());  //the minimum possible value of the largest sum is the maximum element in the array because we cannot split an element into smaller parts, so the largest sum must be at least as large as the largest element in the array
        int high = accumulate(nums.begin(), nums.end(), 0);  //the maximum possible value of the largest sum is the sum of all elements in the array because we can split the array into k subarrays, so the largest sum must be at most the sum of all elements in the array

        while(low <= high){
            int mid = low + (high-low) / 2;

            int split = findsplit(nums, mid);

            if(split <= k){  //to minimize the largest sum we need to check if we can split the array into k subarrays with the current mid value as the largest sum, if we can then we need to check for a smaller value of mid so we move high to mid - 1
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return low;  //the minimum possible value of the largest sum is the maximum element in the array because we cannot split an element into smaller parts, so the largest sum must be at least as large as the largest element in the array
    }
};