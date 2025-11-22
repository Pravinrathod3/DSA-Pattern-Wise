#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        for(int i=0; i<n; i++){
            for(int j=0; j<=i; j++){

                if(i == 0 && j == 0){     //top element dont change
                    continue;
                }
                else{
                    int left = INT_MAX;    //left diagonal element
                    int up = INT_MAX;     //up diagonal element
                    
                    if(j < i){          //up diagonal element exists
                      up = triangle[i-1][j];
                    }

                    if(j-1 >= 0){           //left diagonal element exists
                        left = triangle[i-1][j-1];
                    }

                    triangle[i][j] = min(up, left) + triangle[i][j];   //updating current element with minimum path sum to reach there from top and left diagonal
                   
                }
            }
        }

        int mini = INT_MAX;

        for(int i=0; i<triangle[n-1].size(); i++){   
            mini = min(mini, triangle[n-1][i]);      //finding minimum element from last row
        }

        return mini;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> triangle = {
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3}
    };

    cout << sol.minimumTotal(triangle) << endl; // Output: 11
    return 0;
}

// Time Complexity: O(N^2) where N is the number of rows in the triangle.
// Space Complexity: O(1) as we are modifying the triangle in place.