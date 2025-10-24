#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    vector<string> ans;
    
    void mark(int i, int j, string& res){
        
        if(i == -1 && j == 0){
            res += 'U';
        }
        else if(i == 0 && j == -1){
            res += 'L';
        }
        else if(i == 0 && j == 1){
            res += 'R';
        }
        else{
            res += 'D';
        }
        
    }
    
    void unmark(string& res){
        res.pop_back();
    }
    
    void dfs(int row, int col, vector<vector<int>>& visited, vector<vector<int>>& maze, string& res, int n){
        
        if(row == n-1 && col == n-1){
            ans.push_back(res);
            return ;
        }
        
        visited[row][col] = 1;
        
        int rowdir[4] = {-1, 0, 0, 1};
        int coldir[4] = {0, -1, 1, 0};
        
        for(int i=0; i<4; i++){
            int r = row + rowdir[i];
            int c = col + coldir[i];
            
            if(r < 0 || r >= n || c < 0 || c >= n) continue;
            
            if(!visited[r][c] && maze[r][c] != 0){
                mark(rowdir[i], coldir[i], res);
                dfs(r, c, visited, maze, res, n);
                unmark(res);
            }
        }
        
        visited[row][col] = 0;
    }
  
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        
        string res;
        
        vector<vector<int>> visited(n, vector<int>(n, 0));
        
        
        dfs(0, 0, visited, maze, res, n);
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};

int main(){
    int n = 4;

    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    
    Solution obj;
    vector<string> result = obj.ratInMaze(maze);
    
    for(const string& path : result){
        cout << path << " ";
    }
    
    return 0;
}

//TC: O(4^(n*n))
//SC: O(n*n)