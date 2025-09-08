#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<int> visited(V);
        
        for(int i=0; i<V; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        queue<pair<int, int>> qu;
        
        qu.push({0, -1});
        visited[0] = 1;
        
        while(!qu.empty()){
            auto [node, prevnode] = qu.front();
            int n = qu.size();
            qu.pop();
            
            for(int i=0; i<adj[node].size(); i++){
                if(!visited[adj[node][i]]){
                  qu.push({adj[node][i], node});
                  visited[adj[node][i]] = 1;
                
                }
                else if(adj[node][i] == prevnode) continue;
                else{
                    return true;
                }
                
            }
            
        }
        return false;
    }
};

int main(){
    Solution sol;
    int V = 4;
    int E = 2;
    vector<vector<int>> edges = {{1,2},{2,3}};
    bool result = sol.isCycle(V, edges);
    
    if(result) {
        cout << "Graph contains a cycle." << endl;
    } else {
        cout << "Graph does not contain a cycle." << endl;
    }
    
    return 0;
}