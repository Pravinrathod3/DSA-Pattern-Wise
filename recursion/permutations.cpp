#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void permutations(vector<int>& nums, int index, int n, vector<vector<int>>& ans){
        if(n == index){
            ans.push_back(nums);
            return;
        }

        for(int i=index; i<n; i++){
            swap(nums[i], nums[index]);

            permutations(nums, index+1, n, ans);
            swap(nums[i], nums[index]);
        }
    }


    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();

        permutations(nums, 0, n, ans);

        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = sol.permute(nums);

    for(const auto& perm : result){
        for(int num : perm){
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}