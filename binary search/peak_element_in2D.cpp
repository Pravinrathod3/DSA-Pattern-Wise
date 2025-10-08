#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int low = 0;
        int high = m-1;

        while(low <= high){
            int mid = (low + high) / 2;
            int col = max_element(mat[mid].begin(), mat[mid].end()) - mat[mid].begin();


            int up = mid - 1 >= 0 ? mat[mid-1][col] : -1;
            int down = mid + 1 < m ? mat[mid+1][col] : -1;

            if(mat[mid][col] > up && mat[mid][col] > down){
                return {mid, col};
            }

            if(down > mat[mid][col]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }

        return {-1, -1};
    }
};

int main(){
    Solution sol;
    vector<vector<int>> mat = {{1,4},{3,2}};
    vector<int> peak = sol.findPeakGrid(mat);
    cout << "Peak element found at: (" << peak[0] << ", " << peak[1] << ")" << endl;
    return 0;
}