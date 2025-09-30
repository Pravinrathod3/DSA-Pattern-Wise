#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool dfs(int node, vector<int>& visited, stack<int>& st, vector<vector<int>>& adj, vector<int>& pathvisited){
        visited[node] = 1;
        pathvisited[node] = 1;    // mark the node in the current path

        for(auto it: adj[node]){
            if(!visited[it]){
                if(dfs(it, visited, st, adj, pathvisited)){   
                    return true;
                }
            }
            else if(pathvisited[it]){
                return true;                   // cycle detected
            }
        }

        st.push(node);                      // push the node to stack after all its adjacent nodes are processed
        pathvisited[node] = 0;
        return false;             // no cycle detected
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        
        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        vector<int> visited(numCourses, 0);
        vector<int> pathvisited(numCourses, 0);

        stack<int> st;

        for(int i=0; i<numCourses; i++){
            if(!visited[i]){
                if(dfs(i, visited, st, adj, pathvisited)){
                    return {};                     // if cycle is detected, return empty array
                }
            }
        }

        vector<int> ans;
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();                        
        }

        return ans;
        
    }
};

int main(){
    Solution sol;
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1,0},{2,0},{3,1},{3,2}};
    vector<int> ans = sol.findOrder(numCourses, prerequisites);
    for(auto it: ans){
        cout << it << " ";
    }
    cout << endl;
    return 0;
}// Time Complexity: O(V + E)
// Space Complexity: O(V + E) + O(V) + O(V) + O(V) ~ O(V + E)