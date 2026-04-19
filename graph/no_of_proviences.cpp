class Solution {
public:

    void dfs(int node, vector<vector<int>>& isConnected, vector<int>& visited){
        

        for(int i=0; i<isConnected.size(); i++){
            if(!visited[i] && isConnected[node][i] == 1){
                visited[node] = 1;
                dfs(i, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int cnt = 0;
        int n = isConnected.size();
        vector<int> visited(n, 0);

        for(int i=0; i<n; i++){
            if(!visited[i]){
                cnt++;
                dfs(i, isConnected, visited);
            }
        }

        return cnt;
    }
};