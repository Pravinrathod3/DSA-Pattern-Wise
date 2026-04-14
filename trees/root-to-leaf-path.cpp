/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  
    vector<vector<int>> ans;
    
    void dfs(Node* node, vector<int>& res){
        if(node == NULL) return;
        
        res.push_back(node->data);
        
        if(node->left == NULL && node->right == NULL){
            ans.push_back(res);
        }
        else{
            dfs(node->left, res);
            dfs(node->right, res);
        }
        
        
        
        res.pop_back();
        
        
        
        
    }
   
    vector<vector<int>> Paths(Node* root) {
        vector<int> res;
        
        dfs(root, res);
        
        return ans;
        
    }
};