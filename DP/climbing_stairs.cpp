#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int recurse(int n, vector<int>& dp){
        if(n < 2){
          return 1;
       }

       if(dp[n] != -1) return dp[n];

       return dp[n] = recurse(n-1, dp) + recurse(n-2, dp);
    }

    int climbStairs(int n) {

        vector<int> dp(n+1, -1);
        
        return recurse(n, dp);

    }
};

int main(){
    Solution sol;
    int n;
    cout << "Enter number of stairs: ";
    cin >> n;
    cout << "Number of ways to climb to the top: " << sol.climbStairs(n) << endl;
    return 0;
}

//Time Complexity: O(n)
//Space Complexity: O(n)