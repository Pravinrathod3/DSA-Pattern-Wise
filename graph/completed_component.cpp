class Solution {
public:

    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited, int& nodes, int& edge){
        visited[node] = 1;
        nodes++;

        edge += adj[node].size();

        for(auto it: adj[node]){
            if(!visited[it]){
                dfs(it, adj, visited, nodes, edge);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int component = 0;
        vector<int> visited(n, 0);

        vector<vector<int>> adj(n);

        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        for(int i=0; i<n; i++){
            if(!visited[i]){
                int n = 0;
                int edge = 0;

                dfs(i, adj, visited, n, edge);

                edge = edge / 2;

                int e = (n * (n-1)) / 2;

                if(edge == e) component++;

                
            }
        }

        return component;
    }
};