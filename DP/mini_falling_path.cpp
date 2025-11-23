#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> dp(n, vector<int> (n, -1));   // DP table

        int mini = INT_MAX; 

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){

                if(i == 0){             //top row deals with base case
                    dp[i][j] = matrix[i][j];
                }
                else{
                    int left = INT_MAX;
                    int right = INT_MAX;
                    
                    if(j > 0){                //checking for left diagonal
                      left = dp[i-1][j-1];
                    }

                    int mid = dp[i-1][j];    //checking for middle element

                    if(j < n-1){              //checking for right diagonal
                        right = dp[i-1][j+1];
                    }

                    dp[i][j] = min({left, mid, right}) + matrix[i][j]; 
                    
                }
            }
        }

        for(auto it: dp[n-1]){
            mini = min(mini, it);    //finding minimum in last row
        }

        return mini;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> matrix = {
        {2,1,3},
        {6,5,4},
        {7,8,9}
    };

    cout << "Minimum Falling Path Sum: " << sol.minFallingPathSum(matrix) << endl;

    return 0;
}

// Time Complexity: O(n^2)
// Space Complexity: O(n^2)