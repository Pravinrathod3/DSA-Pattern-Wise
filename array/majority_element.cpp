#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> hash;
        int n = nums.size();

        vector<int> ans;

        for(int i=0; i<n; i++){
           hash[nums[i]]++;
           

           if(hash[nums[i]] > (n/3) ){
            if(ans.empty() || ans.back() != nums[i]){
                ans.push_back(nums[i]);
            }

            if(ans.size() == 2){
                break;
            }
             
           }

        }

        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {3,2,3};
    vector<int> result = sol.majorityElement(nums);

    cout << "Majority elements (appearing more than n/3 times): ";
    for(int num : result){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}