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

    void dfs(TreeNode* root, int row, int col, map<int, map<int, multiset<int> >>& mpp){
        if(root == NULL) return ;

        mpp[col][row].insert(root->val);    // if there are multiple nodes at the same position, we need to sort them by their values. We can use a multiset to store the values at each position, which will automatically sort them.

        dfs(root->left, row+1, col-1, mpp);
        dfs(root->right, row+1, col+1, mpp);

        
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int> >> mpp;  // col -> row -> values (sorted)

        dfs(root, 0, 0, mpp);

        vector<vector<int>> ans;

        for(auto& [col, rownodes]: mpp){           // iterate over columns in sorted order
            vector<int> rowsn; 
            
            for(auto& [key, value]: rownodes){     // iterate over rows in sorted order
                rowsn.insert(rowsn.end(), value.begin(), value.end()); // insert all values at this position into the result for this column
            }

            ans.push_back(rowsn);

        }

        return ans;


    }
};