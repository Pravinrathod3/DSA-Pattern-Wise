#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;

        for(int i=0; i<=n-k; i++){
            int sum = 0;
            map<int, int> hash;
            for(int j=i; j<k+i; j++){
               hash[nums[j]]++;
            }

            vector<pair<int, int>> freq(hash.begin(), hash.end());

            sort(freq.begin(), freq.end(), [](auto &a, auto &b){
                if(a.second == b.second){
                    return a.first > b.first;
                }
                return a.second > b.second;
            });

            for(int i=0; i< min(x, (int)freq.size()); i++){
                sum += freq[i].first * freq[i].second;
            }

            ans.push_back(sum);


        }

        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,2,2,3,1};
    int k = 3, x = 2;
    vector<int> result = sol.findXSum(nums, k, x);  
    for(int val : result){
        cout << val << " ";
    }
    return 0;
}

// Time Complexity: O(n * k log k) where n is the size of the array and k is the size of the subarray.
// Space Complexity: O(k) for the hash map used to store frequencies.