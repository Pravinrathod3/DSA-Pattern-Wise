#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();

        vector<int> hash(101, 0);

        for(int i=0; i<n; i++){
            hash[nums[i]]++;
        }

        int maxi = 0;

        for(auto it: hash){
            maxi = max(maxi, it);
        }

        int sum = 0;

        for(int i=0; i<hash.size(); i++){
            if(hash[i] == maxi){
                sum += maxi;
            }
        }
        

        return sum;
    }
};

int main(){
    Solution s;

    vector<int> nums = {1,3,2,2,5,2,3,7};

    cout<<s.maxFrequencyElements(nums);

    return 0;
}