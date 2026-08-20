class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        if(grid[0][0] == 1 || grid[m-1][n-1] == 1 ) return -1;
    
        queue<pair<int, pair<int, int>>> qu;

        vector<vector<int>> visited(m, vector<int> (n, INT_MAX));
        
        qu.push({0,{0,1}});
        visited[0][0] = 1;

        int rdir[8] = {0, 1, 0, -1, 1, 1, -1, -1};
        int cdir[8] = {1, 0, -1, 0, 1, -1, 1, -1};
        
        while(!qu.empty()){
            auto [row, it] = qu.front();
            auto [col, dist] = it;
            qu.pop();
            
            for(int k=0; k<8; k++){
                int i = row + rdir[k];
                int j = col + cdir[k];

                if(i >= 0 && i < m && j >= 0 && j < n){
                    if(grid[i][j] == 0 && visited[i][j] > dist+1){
                        qu.push({i, {j, dist+1}});
                        visited[i][j] = dist+1;
                    }
                }


            }
        }

        if(visited[m-1][n-1] == INT_MAX) return -1;

        return visited[m-1][n-1];

 

    }
};