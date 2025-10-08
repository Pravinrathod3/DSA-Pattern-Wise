#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int row = 0;
        int col = n-1;

        while(row < m &&  col >= 0){

            int val = matrix[row][col];

            if(val == target){
                return true;
            }
            else if(val > target){
                col--;    
            }
            else{
                row++;
                
            }
        }

        return false;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> mat = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 3;
    bool found = sol.searchMatrix(mat, target);
    cout << (found ? "Target found!" : "Target not found.") << endl;
    return 0;
}