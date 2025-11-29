#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();

        stack<int> st;                // Monotonic Stack - it will store elements in decreasing order from top to bottom
        unordered_map<int, int> mpp;    // Map to store the next greater element for each element in nums2

        for(int i=n-1; i>=0; i--){
            
            while(!st.empty() && st.top() < nums2[i]){   // Pop elements smaller than the current element
                st.pop();
            }
            

            if(st.empty()){                    // If stack is empty, there is no greater element
                mpp[nums2[i]] = -1;
            }
            else{                                // The top element is the next greater element
                mpp[nums2[i]] = st.top();
            }

            st.push(nums2[i]);               // Push the current element onto the stack
        }

        
        vector<int> ans;

        for(auto it: nums1){
            ans.push_back(mpp[it]);      // Get the next greater element from the map
        } 

        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};

    vector<int> result = sol.nextGreaterElement(nums1, nums2);

    for(int val : result){
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

// Time Complexity: O(N + M) where N is the size of nums2 and M is the size of nums1
// Space Complexity: O(N) for the stack and map used to store next greater elements