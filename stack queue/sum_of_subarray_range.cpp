class Solution {
public:

    long long mod = 1e9 + 7;
    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        long long ans = 0;

        vector<int> prev(n), next(n);  //use to store the distance of the current element from the previous smaller element and the next smaller element

        stack<int> st;

        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){  //if the current element is smaller than the top of the stack, then we pop the stack until we find a smaller element or the stack becomes empty
                st.pop();
            }

            prev[i] = st.empty() ? (i + 1) : (i - st.top());

            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i=n-1; i>=0; i--){        //we traverse the array from the end to find the next smaller element for each element in the array
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }

            next[i] = st.empty() ? (n - i) : (st.top() - i);

            st.push(i);
        }

        for(int i=0; i<n; i++){
            ans = (ans + (long long)arr[i] * prev[i] * next[i] ); //the contribution of each element to the sum of subarray minimums is the value of the element multiplied by the number of subarrays in which it is the minimum element, which is given by prev[i] * next[i]
        }

        return ans;
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();

        long long ans = 0;

        vector<int> prev(n), next(n);  //use to store the distance of the current element from the previous greater element and the next greater element

        stack<int> st;

        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] <= arr[i]){
                st.pop();
            }

            prev[i] = st.empty() ? (i + 1) : (i - st.top());

            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] < arr[i]){
                st.pop();
            }

            next[i] = st.empty() ? (n - i) : (st.top() - i);

            st.push(i);
        }

        for(int i=0; i<n; i++){
            ans = (ans + (long long)arr[i] * prev[i] * next[i] ) ;  //the contribution of each element to the sum of subarray maximums is the value of the element multiplied by the number of subarrays in which it is the maximum element, which is given by prev[i] * next[i]
        }

        return ans;
    }

    long long subArrayRanges(vector<int>& nums) {
        return (sumSubarrayMaxs(nums) - sumSubarrayMins(nums));  //the sum of subarray ranges is the difference between the sum of subarray maximums and the sum of subarray minimums
    }
};