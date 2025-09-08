#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        vector<int> ans;
        queue<int> qu;
        qu.push(0);
        int n = adj.size();
        vector<int> visited(n, 0);
        visited[0] = 1;
        
        
        
        while(!qu.empty()){
            
            int node = qu.front();
            
            qu.pop();
            ans.push_back(node);
            
            for(auto it : adj[node]){
                if(!visited[it]){
                    qu.push(it);
                    visited[it] = 1;
                }
            }
        }
        
       
        
        return ans;
    }
};

int main(){
    
    vector<vector<int>> adj = {{1,2}, {0, 3, 4}, {0}, {1}, {1, 5}, {4}};
   
    Solution obj;
    vector<int> ans = obj.bfs(adj);
    for (auto i : ans) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}