#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n = nums.size();

        if(n ==0 ) return 0;
        unordered_set<int> s(nums.begin(), nums.end());   //inserting all elements in the set

        int maxi = 0;

        for(auto it : s){
            if(!s.count(it-1)){     //to find the starting point of the sequence
                int current = it;
                int cnt = 1;

                while(s.count(current + 1)){   //counting the length of the sequence
                    cnt++;
                    current++;
                }

                maxi = max(maxi, cnt);
            }
        }

        

        return maxi;
    }
};

int main(){

    Solution s;

    vector<int> nums = {100,4,200,1,3,2};

    cout<<s.longestConsecutive(nums)<<endl;

    return 0;
}