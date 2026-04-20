class Solution {
public:


    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int> (n, 0));
        queue<pair<pair<int,int>, int >> qu;

        int time = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2 && !visited[i][j]){
                   visited[i][j] = 2;
                   qu.push({{i, j}, time});
                }
            }
        }

        int drow[4] = {0, 1, 0, -1};
        int dcol[4] = {-1, 0, 1, 0};



        while(!qu.empty()){
            auto it = qu.front();
            qu.pop();

            int i = it.first.first;
            int j = it.first.second;
            int t = it.second;

            time = max(time, t);

            for(int k=0; k<4; k++){
                int nrow = i+drow[k];
                int ncol = j+dcol[k];

                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1 && !visited[nrow][ncol]){
                    visited[nrow][ncol] = 2;
                    qu.push({{nrow, ncol}, t+1});
                }
            }


        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1 && visited[i][j] != 2){
                    return -1;
                }
            }
        }



        return time;
    }
};