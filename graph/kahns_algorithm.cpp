#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
  
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        
        vector<int> order(V);
        
        for(int i=0; i<V; i++){
            for(int j=0; j<adj[i].size(); j++){
                order[adj[i][j]]++;
            }
        }
        
        queue<int> qu;
        
        for(int i=0; i<V; i++){
            if(order[i] == 0){
                qu.push(i);
            }
        }
        
        vector<int> ans;
        
        while(!qu.empty()){
            int node = qu.front();
            qu.pop();
            
            for(int i=0; i<adj[node].size(); i++){
                order[adj[node][i]]--;
                if(order[adj[node][i]] == 0){
                    qu.push(adj[node][i]);
                }
            }
            
            ans.push_back(node);
        }
        
        return ans;
        
    }
};

int main(){
    Solution sol;
    int V = 6;
    vector<vector<int>> edges = {{5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1}};
    
    vector<int> result = sol.topoSort(V, edges);
    
    cout << "Topological Sort Order: ";
    for(int i : result){
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}