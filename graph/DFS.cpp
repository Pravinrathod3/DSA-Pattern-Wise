#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
   void recursedfs(vector<vector<int>>& adj, vector<int>& ans, int node, vector<int>& visited){
       ans.push_back(node);
       visited[node] = 1;
       for(int i=0; i<adj[node].size(); i++){
           if(!visited[adj[node][i]]){
                recursedfs(adj, ans, adj[node][i], visited);
           }
       }
   }
  
    vector<int> dfs(vector<vector<int>>& adj) {
        vector<int> ans;
        int n = adj.size();
        int node = 0;
        vector<int> visited(n, 0);
        
        recursedfs(adj, ans, node, visited);
        
        return ans;
    }
};

int main(){
    Solution sol;
    int V = 5;
    vector<vector<int>> adj = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};

    
    vector<int> result = sol.dfs(adj);
    
    for(int node : result){
        cout << node << " ";
    }
    
    return 0;
}