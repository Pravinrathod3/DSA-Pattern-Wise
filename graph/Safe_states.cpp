//Variations of cycle detection in directed graph

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
 
    bool dfs(int node, vector<int>& visited, vector<int>& pathvisited, vector<vector<int>>& graph){
        visited[node] = 1;
        pathvisited[node] = 1;

        for(int i=0; i<graph[node].size(); i++){ // traversing all the adjacent nodes
            if(!visited[graph[node][i]]){
                if(dfs(graph[node][i], visited, pathvisited, graph)){
                    return true;
                }
            }
            else if(pathvisited[graph[node][i]]){       // cycle detected
                return true;
            }
        }

        pathvisited[node] = 0;                         // backtracking
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> visited(n, 0);
        vector<int> pathvisited(n, 0);

        vector<int> ans;

        for(int i=0; i<n; i++){
            if(!visited[i]){
               dfs(i, visited, pathvisited, graph);
            }
        }

        for(int i=0; i<n; i++){
            if(visited[i] == 1 && pathvisited[i] == 0){
                ans.push_back(i);
            }
        }


        return ans;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> graph = {{1,2},{2,3},{5},{0},{5},{},{}};
    vector<int> result = sol.eventualSafeNodes(graph);

    for(int val : result){
        cout << val << " ";
    }
    cout << endl;

    return 0;
}