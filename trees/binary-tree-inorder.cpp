/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;

        TreeNode* node = root;

        if(root == NULL) return ans;

        while(1){
           if(node == NULL){             // if node is null means we have reached the end of a left subtree, so we need to backtrack and visit the parent node and then move to the right subtree
            if(st.empty()) break;        // if the stack is empty, it means we have visited all the nodes in the tree, so we can break out of the loop
            node = st.top();             // we backtrack to the parent node by popping the top node from the stack, which is the last node we visited before reaching the null node
            ans.push_back(node->val);    // we add the value of the parent node to the answer vector, as we are now visiting it after backtracking
            st.pop();
            node = node->right;           // after visiting the parent node, we move to the right subtree by setting the current node to the right child of the parent node, and the process continues until we have visited all nodes in the tree
            
           }
           else{                    // if the current node is not null, we need to keep going left and pushing the nodes onto the stack until we reach a null node, which means we have reached the end of a left subtree
             st.push(node);
             node = node->left;

           }
        }
        

        return ans;
    }
};