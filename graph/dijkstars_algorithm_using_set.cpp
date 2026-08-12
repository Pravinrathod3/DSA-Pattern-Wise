class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<int> dist(V, INT_MAX);
       
       vector<vector<pair<int, int>>> adj(V); // {dist, neighbour)
       
       for(auto it: edges){
           adj[it[0]].push_back({it[2], it[1]});
           adj[it[1]].push_back({it[2], it[0]});
       }
       
       set<pair<int, int>> st;
       
       st.insert({0, src});
       dist[src] = 0;
       
       while(!st.empty()){
           auto [len, node] = *st.begin();
           st.erase(st.begin());
           
           for(auto it: adj[node]){
               auto [weight, adjnode] = it;
               
               if(weight+len < dist[adjnode]){
                   
                   if(dist[adjnode] !=  INT_MAX){
                       st.erase({dist[adjnode], adjnode});
                   }
                   
                   dist[adjnode] = weight+len;
                   
                   st.insert({dist[adjnode], adjnode});
               }
           }
       }
       
       return dist;
        
    }
};