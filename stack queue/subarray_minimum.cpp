class Solution {
public:

    long long mod = 1e9 + 7;               //it is used to store the final answer as it can be very large so we take modulo with 1e9+7
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        long ans = 0;

        vector<int> prev(n), next(n); //to store the distance of previous smaller and next smaller element for each element

        stack<int> st;

        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }

            prev[i] = st.empty() ? (i + 1) : (i - st.top()); //if stack is empty then all previous elements are greater so distance is i+1 else distance is i - index of previous smaller element
 
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }

            next[i] = st.empty() ? (n - i) : (st.top() - i);  //if stack is empty then all next elements are greater so distance is n-i else distance is index of next smaller element - i

            st.push(i);
        }

        for(int i=0; i<n; i++){
            ans = (ans + (long)arr[i] * prev[i] * next[i] ) % mod;  //calculating contribution of each element and adding it to the final answer
        }

        return ans;
    }
};

//TC: O(N)
//SC: O(N)