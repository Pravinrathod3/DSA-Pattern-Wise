#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;    // Monotonic Stack - it will store indices of temperatures in decreasing order
        
        vector<int> ans(n);

        for(int i=n-1; i>=0; i--){

            while(!st.empty() && temperatures[st.top()] <= temperatures[i]){   // Pop indices of temperatures smaller or equal to the current temperature
                st.pop();
            }

           if(st.empty()){
             ans[i] = 0;
           }
           else{
             ans[i] = st.top() - i;   // The difference in indices gives the number of days to wait
           }

           st.push(i);
        }

        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> temperatures = {73,74,75,71,69,72,76,73};

    vector<int> result = sol.dailyTemperatures(temperatures);

    for(int val : result){
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

// Time Complexity: O(N) where N is the size of temperatures
// Space Complexity: O(N) for the stack used to store indices