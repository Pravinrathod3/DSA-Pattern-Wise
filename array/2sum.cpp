#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> ans;
        
        for(int i=0; i<n; i++){
            ans.push_back({i, nums[i]});
        }

        sort(ans.begin(), ans.end(), [](auto &a, auto &b){
           return a.second < b.second;
        });

        int i=0;
        int j=n-1;

        while(i < j){
           int sum = ans[i].second + ans[j].second;

           if(sum == target){
              return {ans[i].first, ans[j].first};
           }
           else if(sum < target){
            i++;
           }
           else{
            j--;
           }
        }

        return {-1, -1};
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = sol.twoSum(nums, target);
    cout << "Indices: " << result[0] << ", " << result[1] << endl;
    return 0;
}