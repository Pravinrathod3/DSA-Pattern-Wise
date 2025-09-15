#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool dfs(int i, vector<int>& visited, vector<int>& pathvisited, vector<vector<int>>& adj){
        visited[i] = 1;
        pathvisited[i] = 1;
        

        for(auto it: adj[i]){
            if(!visited[it]){
                if(dfs(it, visited, pathvisited, adj) == true){
                return true;
              }
            }
            else if(pathvisited[it]){
                return true;
            }
            
        }
        
        pathvisited[i] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        
        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        vector<int> visited(numCourses, 0);
        vector<int> pathvisited(numCourses, 0);

        for(int i=0; i<numCourses; i++){
            if(!visited[i]){
                if(dfs(i, visited, pathvisited, adj) == true){
                    return false;
                }
            }
        }

        return true;


    }
};

int main(){
    Solution sol;
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1,0},{0,1}};
    cout << (sol.canFinish(numCourses, prerequisites) ? "true" : "false") << endl; // Output: false
    return 0;
}