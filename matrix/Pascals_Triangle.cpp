#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        int m = numRows;

        for(int i=1; i<m+1; i++){
            int res = 1;
            vector<int> col;
            col.push_back(res);
            for(int j=1; j<i; j++){
               res = res * (i-j);
               res = res / j;
               col.push_back(res);
            }

            ans.push_back(col);
        }

        return ans;
    }
};

int main(){
    Solution sol;
    int numRows = 5;
    vector<vector<int>> result = sol.generate(numRows);

    for(const auto& row : result){
        for(int val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}