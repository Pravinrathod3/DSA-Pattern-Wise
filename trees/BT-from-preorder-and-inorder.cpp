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

   TreeNode* divide(int prestart, int preend, vector<int>& preorder, int instart, int inend, vector<int>& inorder, map<int, int>& mpp){

    if(prestart > preend || instart > inend) return NULL;  // base case: if the current segment of the preorder or inorder traversal is invalid, return NULL
       
       TreeNode* root = new TreeNode(preorder[prestart]); // create a new TreeNode with the value of the current root (the first element of the current segment of the preorder traversal is the root of the current subtree)

       int inpos = mpp[root->val];  // find the index of the current root in the inorder traversal using the map for O(1) access
       int leftno = inpos - instart;  // calculate the number of nodes in the left subtree (the number of nodes in the left subtree is equal to the index of the current root in the inorder traversal minus the starting index of the current segment of the inorder traversal)

        // recursively construct the left and right subtrees using the corresponding segments of the preorder and inorder traversals

       root->left = divide(prestart+1, prestart+leftno, preorder, instart, inpos-1 , inorder, mpp);  // the left subtree is constructed from the next leftno elements in the preorder traversal (starting from prestart+1) and the corresponding segment of the inorder traversal (from instart to inpos-1)

       root->right = divide(prestart+leftno+1, preend, preorder, inpos+1, inend, inorder, mpp);  // the right subtree is constructed from the remaining elements in the preorder traversal (starting from prestart+leftno+1) and the corresponding segment of the inorder traversal (from inpos+1 to inend)
 
       return root;  // return the constructed subtree rooted at the current root
        
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();

        map<int, int> mpp;   // to store the index of each element in the inorder traversal for O(1) access

        for(int i=0; i<n; i++){
            mpp[inorder[i]] = i;
        }

        TreeNode* ans = divide(0, n-1, preorder, 0, n-1, inorder, mpp); // calling the recursive function to construct the tree

        return ans;
    }
};