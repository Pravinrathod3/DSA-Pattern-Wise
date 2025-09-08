#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        
        
        vector<vector<int>> nodes;
        vector<int> visited(V, 0);
        
        vector<vector<int>> adj(V);
        
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            
        }   

        
        for(int i=0; i<V; i++){
            
                vector<int> res;
                visited[i] = 1;
                res.push_back(i);
                for(int j=0; j<adj[i].size(); j++){
                    if(!visited[adj[i][j]]){
                    visited[adj[i][j]] = 1;
                    res.push_back(adj[i][j]);
                    }
                }
                nodes.push_back(res);
                
            }
        
        
        return nodes;
    }
};

int main() {
    Solution sol;
    int V = 5;
    vector<vector<int>> edges = {{0, 1}, {2, 1}, {3, 4}};
    vector<vector<int>> components = sol.getComponents(V, edges);
    
    for (const auto& component : components) {
        for (int node : component) {
            cout << node << " ";
        }
        cout << endl;
    }
    
    return 0;
}