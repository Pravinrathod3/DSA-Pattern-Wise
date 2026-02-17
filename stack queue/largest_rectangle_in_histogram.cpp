class Solution {
public:

    vector<int> prevsmaller(vector<int> nums){
        vector<int> ans(nums.size());
        stack<int> st;

        for(int i=0; i < nums.size(); i++){
            while(!st.empty() && nums[st.top()] > nums[i]){
                st.pop();
            }

            ans[i] = st.empty() ? -1 : st.top();   //if there is no smaller element to the left of the current element, we set the index of the previous smaller element to be -1, which will help us to calculate the width of the rectangle for the current element in the heights array

            st.push(i);
        }

        return ans;
    }

    vector<int> nextsmaller(vector<int> nums){
        vector<int> ans(nums.size());
        stack<int> st;

        for(int i=nums.size()-1; i>=0; i--){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }

            ans[i] = st.empty() ? nums.size() : st.top();  //if there is no smaller element to the right of the current element, we set the index of the next smaller element to be the size of the heights array, which will help us to calculate the width of the rectangle for the current element in the heights array
            st.push(i);
        }

        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        int ans = 0;

        vector<int> pre = prevsmaller(heights);  // we find the index of the previous smaller element for each element in the heights array, which will help us to calculate the width of the rectangle for each element in the heights array
        vector<int> nex = nextsmaller(heights);  // we find the index of the next smaller element for each element in the heights array, which will help us to calculate the width of the rectangle for each element in the heights array

        for(int i=0; i<n; i++){
            int res = heights[i] * (nex[i]-pre[i]-1);  // width = right - left - 1 * height of the rectangle, where right is the index of the next smaller element and left is the index of the previous smaller element for the current element in the heights array
            ans = max(ans, res);
        }

        return ans;
    }
};