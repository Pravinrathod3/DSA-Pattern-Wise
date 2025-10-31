#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

   bool possible(char num, int row, int col, vector<vector<char>>& board){         //check if num can be placed at board[row][col]
     for(int i=0; i<9; i++){
        if(board[row][i] == num){          //check in row
            return false;
        }

        if(board[i][col] == num){          //check in column
            return false;
        }

        if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num){   //check in 3x3 box
           return false;
        }
     }

     return true;


   }

    bool sudoku(vector<vector<char>>& board){

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] == '.'){              //find empty cell

                    for(char num='1'; num<='9'; num++){        //try placing numbers from 1 to 9
                        if(possible(num, i, j, board)){         
                          board[i][j] = num;                   //place num

                          if(sudoku(board)){                  //recurse
                            return true;                      //if solved, return true
                          }
                          
                            board[i][j] = '.';         //backtrack if not solved
                          

                        }
                        
                    }

                    return false;                    //if no number can be placed, return false
                }
            }
        }

        return true;                                 //if all cells are filled, return true


    }

    void solveSudoku(vector<vector<char>>& board) {

        if(sudoku(board)) return;
        
    }
};

int main(){
    Solution obj;
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    obj.solveSudoku(board);

    for(auto row: board){
        for(auto ch: row){
            cout << ch << " ";
        }
        cout << endl;
    }

    return 0;
}

//TC: O(9^(n*n))
//SC: O(1)