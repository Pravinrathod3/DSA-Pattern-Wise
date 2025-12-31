#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        stack<int> st;          // Monotonic Decreasing Stack


        for(int i= 2 * n-1; i>=0; i--){             // Traverse Twice for Circular Array 1. loop from 2n-1 to n for building stack 2. loop from n-1 to 0 for filling answer
            int ind = i % n;                   // Circular Indexing 
            while(!st.empty() && st.top() <= nums[ind]){     // Pop Smaller Elements
                st.pop();
            }
            
            if(i < n){                 // Fill Answer for First Pass
                if(st.empty()){
                   ans[i] = -1;
                }
                else{
                    ans[i] = st.top();
                }
            }


            st.push(nums[ind]);       // Push Current Element
        }

        return ans;

    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,2,1};
    vector<int> result = sol.nextGreaterElements(nums);
    for(int val : result){
        cout << val << " ";
    }
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)