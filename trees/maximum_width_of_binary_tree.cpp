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
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        queue<pair<TreeNode*, long long>> qu;  // queue to store the node and its index in the level order traversal, to know the width of the current level, we need to know the index of the first and last node in the level, so we can calculate the width as end - start + 1, we use long long to avoid overflow when calculating the index of the child nodes, since the index can grow exponentially with the depth of the tree

        if(root == NULL) return ans;

        qu.push({root, 0});

        while(!qu.empty()){
            int n = qu.size();

            long long start = qu.front().second; // start is minimum index of the current level
            long long end = qu.back().second;   // end is maximum index of the current level

            ans = max(ans, (int)(end-start+1));  // width of the current level is end - start + 1

            for(int i=0; i<n; i++){
                pair<TreeNode*, long long> node = qu.front();
                qu.pop();

                if(node.first->left != NULL) qu.push({node.first->left, (node.second-start)*2+1});  // left child index is parent index * 2 + 1 start from 0 to stop overflow
                if(node.first->right != NULL) qu.push({node.first->right, (node.second-start)*2+2});  // right child index is parent index * 2 + 2 start from 0 to stop overflow
            }
        }

        return ans;
    }
};