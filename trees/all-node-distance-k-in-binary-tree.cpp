/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    unordered_map<TreeNode*, TreeNode*> parent;

    void fill(TreeNode* root){
       queue<TreeNode*> qu;

       qu.push(root);

       while(!qu.empty()){
        TreeNode* node = qu.front();
        qu.pop();

        if(node->left){
            parent[node->left] = node;
            qu.push(node->left);
        }

        if(node->right){
            parent[node->right] = node;
            qu.push(node->right);
        }

       }


    }


    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        fill(root);
        
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> qu;

        qu.push(target);
        visited[target] = true;

        int step = 0;

        while(!qu.empty()){
            int size = qu.size();

            if(k == step) break;

            step++;

            for(int i=0; i<size; i++){
                TreeNode* node = qu.front();
                qu.pop();

                if(node->left && !visited[node->left]){
                    visited[node->left] = true;
                    qu.push(node->left);
                }

                if(node->right && !visited[node->right]){
                    visited[node->right] = true;
                    qu.push(node->right);
                }

                if(parent[node] && !visited[parent[node]]){
                   visited[parent[node]] = true;
                   qu.push(parent[node]);
                }
            }

        }

        vector<int> ans;

        while(!qu.empty()){
            ans.push_back(qu.front()->val);
            qu.pop();
        }

        return ans;
    }
};