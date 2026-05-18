#include<bits/stdc++.h>
using namespace std;

class Solution {
public:


    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> visited(m, vector<int> (n, 0));
        vector<vector<int>> distance(m, vector<int> (n, 0));

        queue<pair<pair<int, int> , int>> qu ;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0){
                    visited[i][j] = 1;
                    distance[i][j] = 0;
                    qu.push({{i, j}, 0});
                }
            }
        }

        int rl[4] = {0, 1, 0, -1};
        int cl[4] = {1, 0, -1, 0};

        while(!qu.empty()){
            auto [top, cnt] = qu.front();
            auto [i, j] = top;

            qu.pop();

            for(int k=0; k<4; k++){
                
                int row = i+rl[k];
                int col = j+cl[k];

                if(row >= 0 && row < m && col >= 0 && col < n){
                    if(!visited[row][col]){
                        visited[row][col] = 1;
                        distance[row][col] = cnt+1;
                        qu.push({{row, col}, cnt+1});
                    }
                }
            }


        }

        return distance;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> mat = {{0,0,0},{0,1,0},{1,1,1}};
    vector<vector<int>> result = sol.updateMatrix(mat);
    
    for(int i=0; i<result.size(); i++){
        for(int j=0; j<result[0].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}