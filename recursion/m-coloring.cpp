#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
  bool safetocolor(int node, vector<vector<int>> &adj, int color, vector<int>& visited){
     for(auto it: adj[node]){
        if(visited[it] == color){
            return false;
        }
     }
     
     return true;
  }
  
  
   bool recurse(int node, vector<int>& visited, int v, vector<vector<int>> &adj, int m){
       
       if(node == v){
           return true;
       }
       
       for(int i=1; i<=m; i++){
           
           if(safetocolor(node, adj, i, visited)){
               visited[node] = i;
           
               if(recurse(node+1, visited, v, adj, m)){
                   return true;
               }
               
               visited[node] = 0;
           }
           
       }
       
       return false;
   }
  
  
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        vector<int> visited(v, 0);
        vector<vector<int>> adj(v);
        
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        if(recurse(0, visited, v, adj, m)){
            return true;
        }
        
        return false;
        
    }
};

int main(){
    Solution obj;
    int v = 4;
    vector<vector<int>> edges = {{0,1}, {1,2}, {2,3}, {3,0}, {0,2}};
    int m = 3;
    if(obj.graphColoring(v, edges, m)){
        cout << "Graph can be colored with " << m << " colors." << endl;
    } else {
        cout << "Graph cannot be colored with " << m << " colors." << endl;
    }
    return 0;
}