#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    vector<vector<string>> ans;

    bool safe(int r, int c, vector<string>& res, int n){
        int row = r;
        int col = c;
        for(int i=0; i<n; i++){
            if(res[row][i] ==  'Q') return false;
            if(res[i][col] == 'Q') return false;
        }

        row = r;
        col = c;

        while(row < n && col < n && row >= 0 && col >= 0){
            if(res[row][col] == 'Q') return false;
            row++;
            col++;
        }

        row = r;
        col = c;

        while(row < n && col >= 0 && row >= 0 && col < n){
            if(res[row][col] == 'Q') return false;
            row++;
            col--;
        }

        row = r;
        col = c;

        while(row >= 0 && col < n && row < n && col >= 0){
            if(res[row][col] == 'Q') return false;
            row--;
            col++;
        }

        row = r;
        col = c;

        while(row >= 0 && col >= 0 && row < n && col < n){
            if(res[row][col] == 'Q') return false;
            row--;
            col--;
        }
         
        return true;

    }

    void backtrack(int col, vector<string>& res, int n){
        if(col == n){
            ans.push_back(res);
            return ;
        }

        for(int i=0; i<n; i++){
            if(safe(i, col, res, n)){
                res[i][col] = 'Q';
                backtrack(col+1, res, n);
                res[i][col] = '.';
            }
            
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> res(n, string(n, '.'));

        backtrack(0, res, n);

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