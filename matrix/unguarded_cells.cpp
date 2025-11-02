#include<bits/stdc++.h>
using namespace std;

class Solution {
public:


    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int> (n, 0));
        vector<vector<bool>> seen(m, vector<bool>(n, false));

        for(int i=0; i<walls.size(); i++){
            grid[walls[i][0]][walls[i][1]] = 2;     //walls = 2;
        }

        for(int i=0; i<guards.size(); i++){
            grid[guards[i][0]][guards[i][1]] = 1;   //guards = 1;
        }

        for (int i = 0; i < m; i++) {
            bool active = false;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) active = false;  // wall breaks view
                else if (grid[i][j] == 1) active = true; // guard activates view
                else if (active) seen[i][j] = true; // visible cell
            }
        }

        // Right → Left
        for (int i = 0; i < m; i++) {
            bool active = false;
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 2) active = false;
                else if (grid[i][j] == 1) active = true;
                else if (active) seen[i][j] = true;
            }
        }

        // Top → Bottom
        for (int j = 0; j < n; j++) {
            bool active = false;
            for (int i = 0; i < m; i++) {
                if (grid[i][j] == 2) active = false;
                else if (grid[i][j] == 1) active = true;
                else if (active) seen[i][j] = true;
            }
        }

        // Bottom → Top
        for (int j = 0; j < n; j++) {
            bool active = false;
            for (int i = m - 1; i >= 0; i--) {
                if (grid[i][j] == 2) active = false;
                else if (grid[i][j] == 1) active = true;
                else if (active) seen[i][j] = true;
            }
        }

        // Count unguarded
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 && !seen[i][j]) cnt++;
            }
        }

        return cnt;
    }
};

int main(){
    Solution sol;
    int m = 4, n = 6;
    vector<vector<int>> guards = {{0,0},{1,1},{2,3}};
    vector<vector<int>> walls = {{0,1},{2,2},{1,4}};
    cout << sol.countUnguarded(m, n, guards, walls) << endl; // Output the count of unguarded cells
    return 0;
}