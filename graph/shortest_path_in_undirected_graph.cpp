class Solution {
  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        vector<vector<int>> adj(V);
        
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        
        queue<int> qu;
        
        qu.push(src);
        
        while(!qu.empty()){
            auto node = qu.front();
            qu.pop();
            
            for(auto it: adj[node]){
                if(dist[it] > dist[node]+1){
                    dist[it] = dist[node]+1;
                    
                    qu.push(it);
                }
            }
        }
        
        if(dist[dest] == INT_MAX) return -1;
        
        return dist[dest];
        
    }
};
