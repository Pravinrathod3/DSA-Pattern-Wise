#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size()-1;
        int index;

        for(int i=n-1; i>=0; i--){
            if(nums[i] < nums[i+1]){
                index = i;
                break;
            }
        }

        if(index == -1){
            reverse(nums.begin(), nums.end());
            return ;
        }

        for(int i=n; i>index; i--){
            if(nums[i] > nums[index]){
                swap(nums[i], nums[index]);
                break;
            }
        }

        reverse(nums.begin()+(index+1), nums.end());


    }
};

int main(){
    Solution obj;
    vector<int> nums = {1,2,3};
    obj.nextPermutation(nums);

    for(auto it: nums){
        cout<<it<<" ";
    }
}