#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void quicksort(vector<int>& nums, int low, int high){

        if(low >= high){
            return;
        }

        int piviot = nums[low];
        int i = low, j = high;

        while(i <= j){
            while(i <= high && nums[i] <= piviot){
               i++;
            }
            while(j >= low && nums[j] > piviot){
                j--;
            }
            if(i < j){
                swap(nums[i], nums[j]);
            }


        }

        swap(nums[low], nums[j]);

        quicksort(nums, low, j-1);
        quicksort(nums, j+1, high);
    }

    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums, 0, nums.size()-1);

        return nums;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {5,2,3,1};
    vector<int> sorted = sol.sortArray(nums);

    for(int num : sorted){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}