#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        vector<vector<int>> visited(n, vector<int> (m, 0));

        visited[sr][sc] = color;

        queue<pair<int, int>> qu;

        qu.push({sr, sc});

        int adji[4] = {0, -1, 0, 1};
        int adjj[4] = {-1, 0, 1, 0};

        while(!qu.empty()){
            auto [i, j] = qu.front();
            qu.pop();

            for(int k=0; k<4; k++){
                if(n > (i + adji[k]) && (i + adji[k]) >= 0 && m > (j + adjj[k]) && (j + adjj[k]) >= 0){
                    if(image[i + adji[k]][j + adjj[k]] == image[i][j] && visited[i + adji[k]][j + adjj[k]] != color){
                        visited[i + adji[k]][j + adjj[k]] = color;
                        qu.push({i + adji[k], j + adjj[k]});
                    }
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(visited[i][j] != color){
                    visited[i][j] = image[i][j];
                }
            }
        }

        return visited;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    int sr = 1, sc = 1, color = 2;
    vector<vector<int>> result = sol.floodFill(image, sr, sc, color);
    
    for(const auto& row : result) {
        for(const auto& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}