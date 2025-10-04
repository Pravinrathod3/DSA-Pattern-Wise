#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 1;                           // Start from 1 since we are checking mid-1
        int high = n-2;                       // End at n-2 since we are checking mid+1

        if(n == 1) return 0;

        if(nums[0] > nums[1]) return 0;                 // Check if the first element is a peak
        if(nums[n-1] > nums[n-2]) return n-1;           // Check if the last element is a peak

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[mid] > nums[mid+1] && nums[mid] > nums[mid-1]){      // Check if mid is a peak
                return mid;
            }

            if(nums[mid] > nums[mid-1]){                                  // If mid is greater than mid-1, then the peak must be in the right half
                low = mid+1;
            }
            else{
                high = mid - 1;                       // If mid is less than mid-1, then the peak must be in the left half
            }
        }

        return high;                    // Return high which will be at the peak position

    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,2,1,3,5,6,4};
    cout << sol.findPeakElement(nums) << endl; // Output: 5
    return 0;
}