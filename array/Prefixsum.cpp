#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;

        int prefix = 0;
        
        map<int, int> hash;

        hash[0] = 1;

        for(int i=0; i<n; i++){

            prefix += nums[i];

            if(hash[prefix-k] > 0){
                cnt = cnt + hash[prefix-k];
            }

            hash[prefix]++;

        }
        

        return cnt;
    }
};

int main(){
    Solution s;

    vector<int> nums = {1,1,1};
    int k = 2;

    cout<<s.subarraySum(nums, k);

    return 0;
}