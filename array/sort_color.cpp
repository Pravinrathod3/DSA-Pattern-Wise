#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int c1 = 0;
        int c2 = 0;
        int c3 = 0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0) c1++;
            else if(nums[i] == 1) c2++;
            else c3++;
        }

        for(int i=0; i<c1; i++){
            nums[i] = 0;
        }

        for(int i=c1; i<c2+c1; i++){
            nums[i] = 1;
        }

        for(int i=c2+c1; i<c3+c2+c1; i++){
            nums[i] = 2;
        }
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sol.sortColors(nums);
    cout << "Sorted colors: ";
    for(int num : nums){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}