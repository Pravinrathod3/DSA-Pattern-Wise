/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

//In this technique we will use a stack to perform all three traversals in one go. We will use a key to identify the state of the node in the traversal. The key will be 1 for preorder, 2 for inorder and 3 for postorder. We will push the node back to the stack with the updated key after processing it for each traversal.
//the intuition behind this approach is that in preorder traversal we process the node before its children, in inorder traversal we process the node after its left child and before its right child and in postorder traversal we process the node after its children. So we can use the key to identify the state of the node in the traversal and push it back to the stack accordingly.


vector<vector<int>> getTreeTraversal(TreeNode *root){
   vector<int> pre, ino, post;  //preorder, inorder, postorder

   stack<pair<TreeNode*, int>> st; //stack of pair of node and key, key is used to identify the state of the node in the traversal

   st.push({root, 1});

   while(!st.empty()){
       TreeNode* node = st.top().first;   
       int key = st.top().second;
       
       st.pop();     //pop the node from the stack 

       if(key == 1){
           pre.push_back(node->data); //preorder traversal, process the node before its children
           key++;
           st.push({node, key});     //push the node back to the stack with the updated key
           if(node->left != NULL) st.push({node->left, 1});  //push the left child to the stack with key 1 for preorder traversal
       }
       else if(key == 2){
           ino.push_back(node->data);
           key++;
           st.push({node, key});
           if(node->right != NULL) st.push({node->right, 1});
       }
       else{
           post.push_back(node->data);
       }


   }

   return {ino, pre, post};
}

/*
  For example, if we have the following binary tree:

          1
         / \
        2   3
       / \
      4   5

    The output of the above code will be:
    Inorder: 4 2 5 1 3
    Preorder: 1 2 4 5 3
    Postorder: 4 5 2 3 1

    flow:
    stack: (1, 1)  //preorder traversal, process the node before its children 
    stack: (1, 2) (2, 1)  //preorder traversal, process the node before its children
    stack: (1, 2) (2, 2) (4, 1)  //preorder traversal, process the node before its children
    stack: (1, 2) (2, 2) (4, 2)  //inorder traversal, process the node after its left child and before its right child
    stack: (1, 2) (2, 3) (4, 2)  //postorder traversal, process the node after its children
    stack: (1, 2) (2, 3) (5, 1)  //preorder traversal, process the node before its children
    stack: (1, 2) (2, 3) (5, 2)  //inorder traversal, process the node after its left child and before its right child
    stack: (1, 2) (2, 3) (5, 3)  //postorder traversal, process the node after its children
    stack: (1, 2) (3, 1)  //preorder traversal, process the node before its children
    stack: (1, 2) (3, 2)  //inorder traversal, process the node after its left child and before its right child
    stack: (1, 2) (3, 3)  //postorder traversal, process the node after its children
    stack: (1, 3)  //postorder traversal, process the node after its children


  

*/