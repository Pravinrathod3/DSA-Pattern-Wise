#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int findfirst(vector<int>& nums, int target){
        int n = nums.size();
        int low = 0;
        int high = n-1;

        int res = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[mid] == target){
                res = mid;
                high = mid - 1;
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return res;
    }

    int findlast(vector<int>& nums, int target){
        int n = nums.size();
        int low = 0;
        int high = n-1;

        int res = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[mid] == target){
                res = mid;
                low = mid + 1;
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return res;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
 
        int first = findfirst(nums, target);
        int last = findlast(nums, target);

        return {first, last};
    }
};

int main(){
    Solution sol;
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    vector<int> result = sol.searchRange(nums, target);
    cout << "First and Last Position of Element in Sorted Array: [" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}