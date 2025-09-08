#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void merge(vector<int>& nums, int low, int mid, int high){
        vector<int> temp;
        int i = low;
        int j = mid+1;
        while(i <= mid && j <= high){
            if(nums[i] <= nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        
        while(i <= mid){
            temp.push_back(nums[i]);
            i++;
        }

        while(j <= high){
            temp.push_back(nums[j]);
            j++;
        }
       
       for(int k = low; k <= high; k++){
           nums[k] = temp[k-low];
       }

    }
    
    void mergesort(vector<int>& nums, int i, int j){
         if(i == j){
            return;
        }

        int mid = (i + j) / 2;

        mergesort(nums, i, mid);
        mergesort(nums, mid+1, j);
        merge(nums, i, mid, j);

    }
   
    vector<int> sortArray(vector<int>& nums) {
       int low = 0;
       int high = nums.size()-1;

       mergesort(nums, low, high);

       return nums;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {5, 2, 3, 1};
    
    vector<int> result = sol.sortArray(nums);
    
    for(int num : result){
        cout << num << " ";
    }
    
    return 0;
}