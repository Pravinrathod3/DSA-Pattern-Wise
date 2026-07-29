#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<string>> ans;

    bool safe(int row, int col, vector<string>& temp, int n){
        //left side

        for(int j=col; j>=0; j--){
            if(temp[row][j] == 'Q') return false;
        }

        //cross left up

        int i = row, j = col;

        while(i >= 0 && j >= 0){
            if(temp[i][j] == 'Q') return false;
            i--;
            j--;
        }

        //cross left down

        i = row, j = col;

        while(i < n && j >= 0){
            if(temp[i][j] == 'Q') return false;
            i++;
            j--;
        }

        return true;

    }


    void backtrack(int col, vector<string>& temp, int n){

        if(col == n){
            ans.push_back(temp);
            return;
        }

        for(int i=0; i<n; i++){
            if(safe(i, col, temp, n)){
                temp[i][col] = 'Q';

                backtrack(col+1, temp, n);

                temp[i][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> temp(n, string(n, '.'));

        backtrack(0, temp, n);

        return ans;
    }
};

int main(){
    int n;
    cin >> n;
    Solution sol;
    vector<vector<string>> result = sol.solveNQueens(n);
    
    for (const auto& board : result) {
        for (const auto& row : board) {
            cout << row << endl;
        }
        cout << endl; // Separate different solutions
    }
    
    return 0;
}
