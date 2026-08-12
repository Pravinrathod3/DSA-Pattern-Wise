class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
       vector<int> dist(V, INT_MAX);
       
       vector<vector<pair<int, int>>> adj(V); // {dist, neighbour)
       
       for(auto it: edges){
           adj[it[0]].push_back({it[2], it[1]});
           adj[it[1]].push_back({it[2], it[0]});
       }
       
       priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
       
       pq.push({0, src});
       
       dist[src] = 0;
       
       while(!pq.empty()){
           auto [weight, node] = pq.top();
           pq.pop();
           
           if (weight > dist[node]) continue;
           
           for(auto it: adj[node]){
               auto [adjweight, adjnode] = it;
               
               if(weight+adjweight < dist[adjnode]){
                   dist[adjnode] = weight+adjweight ;
                   pq.push({weight+adjweight , adjnode});
               }
           }
       }
       
       return dist;
        
    }
};