
bool dfs(int node, vector<vector<int>>& adj,vector<int>& visited,vector<int>& pathvisited, stack<int>& st ){
    visited[node] = 1;
    pathvisited[node] = 1;

    for(auto it: adj[node]){
        if(!visited[it]){
            if(dfs(it, adj, visited, pathvisited , st)) return true;
        }
        else if(pathvisited[it]) return true;
    }

    st.push(node);
    pathvisited[node] = 0;

    return false;
}

string getAlienLanguage(vector<string> &dictionary, int k)
{

    int n = dictionary.size();

    vector<vector<int>> adj(k);

    for(int i=0; i<n-1; i++){
        int j = 0;

        while(j < dictionary[i].size() && j < dictionary[i+1].size()){
             int first = dictionary[i][j]-'a';
             int second = dictionary[i+1][j]-'a';

             if(first == second) j++;
             else{
                adj[first].push_back(second);
                break;
             }
        }
    }

    stack<int> st;
    vector<int> visited(k);
    vector<int> pathvisited(k);

    string ans;

    for(int i=0; i<k; i++){
        if(!visited[i]){
            if(dfs(i, adj, visited, pathvisited, st)) return ans;
        }
    }

    while(!st.empty()){
        ans.push_back(st.top()+'a');
        st.pop();
    }

    return ans;


}