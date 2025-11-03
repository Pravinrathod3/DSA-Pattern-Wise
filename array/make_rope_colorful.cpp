#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int cnt = 0;

        for(int i=0; i<colors.size()-1; i++){
            if(colors[i] == colors[i+1]){
                cnt += min(neededTime[i], neededTime[i+1]);
                neededTime[i+1] = max(neededTime[i], neededTime[i+1]);
            }
        }

        return cnt;
    }
};

int main(){
    Solution sol;
    string colors = "aabbbcc";
    vector<int> neededTime = {1, 2, 3, 4, 5, 1, 2};
    cout << sol.minCost(colors, neededTime) << endl; // Output: 9
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)