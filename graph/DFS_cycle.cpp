#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
   
   bool detect(int node,int parent, vector<int>& visited, vector<vector<int>>& adj){
       
        int j = node;
        visited[j] = 1;
        
        for(int i=0; i<adj[j].size(); i++){
            if(!visited[adj[j][i]]){
                if(detect(adj[j][i], j, visited, adj)) return true;
            }
            else if(adj[j][i] != parent){
                return true;
            }
        }
        return false;
   }
  
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<int> visited(V);
        bool ans;
        
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
    
        
        
        for(int i=0; i<V; i++){
            if(!visited[i]){
                
              ans = detect(i, -1, visited, adj);
              if(ans == true){
                  return true;
              }
            }
            
        }
        
        return false;
        
    }
};

int main(){
    Solution sol;
    int V = 5;
    int E = 5;
    vector<vector<int>> edges = {{0,1},{1,2},{2,0},{1,3},{3,4}};
    bool result = sol.isCycle(V, edges);
    
    if(result) {
        cout << "Graph contains a cycle." << endl;
    } else {
        cout << "Graph does not contain a cycle." << endl;
    }
    
    return 0;
}