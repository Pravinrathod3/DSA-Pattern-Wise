#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool bfs(int start, vector<int>& visited, vector<vector<int>>& graph){
        
        queue<int> qu;

        qu.push(start);
        visited[start] = 1;

        while(!qu.empty()){
            int node = qu.front();
            qu.pop();

            for(int i=0; i<graph[node].size(); i++){
                if(!visited[graph[node][i]]){
                   visited[graph[node][i]] = -visited[node];
                   qu.push(graph[node][i]);
                }
                else{
                    if(visited[node] == visited[graph[node][i]]){
                        return false;
                    }
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> visited(n, 0);

        bool ans;

        for(int j=0; j<n; j++){
            if(!visited[j]){
               ans = bfs(j, visited, graph);
               if(ans == false){
                return false;
               }
            }
            
        }


        return ans;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> graph = {{1,3},{0,2},{1,3},{0,2}};
    bool ans = sol.isBipartite(graph);
    if(ans){
        cout << "The graph is Bipartite" << endl;
    }
    else{
        cout << "The graph is not Bipartite" << endl;
    }
    return 0;
}