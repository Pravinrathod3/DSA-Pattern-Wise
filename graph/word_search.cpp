#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool dfs(int index, int row, int col, vector<vector<int>>& visited, vector<vector<char>>& board, string& word){
        visited[row][col] = 1;
        int m = board.size();
        int n = board[0].size();

        if(index == word.size()){
            return true;
        }

        int rowdir[4] = {0, 1, 0, -1};
        int coldir[4] = {1, 0, -1, 0};

        for(int i=0; i<4; i++){
            int siderow = rowdir[i] + row;
            int sidecol = coldir[i] + col;

            if(siderow < 0 || sidecol < 0 || siderow >= m || sidecol >= n) continue;

            if(board[siderow][sidecol] == word[index] && !visited[siderow][sidecol]){
                if(dfs(index+1, siderow, sidecol, visited, board, word)) return true;
            }
        }

        visited[row][col] = 0;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));


        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == word[0]){
                    if(dfs(1, i, j, visited, board, word)){
                        return true;
                    }
                }
            }
        }

        return false;
    }
};

int main(){
    Solution sol;
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    string word = "ABCCED";
    cout << (sol.exist(board, word) ? "True" : "False") << endl; // Output: True
    return 0;
}