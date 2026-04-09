#include<bits/stdc++.h>
using namespace std;

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


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root == NULL || root == p || root == q) return root;   // if root is null or root is either p or q, then return root because it is the lowest common ancestor no need to go further down the tree as if the another node is found in the subtree of the current node then the current node will be the lowest common ancestor
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left == NULL){  // if left is null then it means that both p and q are not found in the left subtree of the current node, so we need to check the right subtree of the current node for p and q, if we find either p or q in the right subtree then we will return that node as the lowest common ancestor because it is the lowest common ancestor of p and q in the right subtree of the current node
           return right;
        }
        else if(right == NULL){  // if right is null then it means that both p and q are not found in the right subtree of the current node, so we need to check the left subtree of the current node for p and q, if we find either p or q in the left subtree then we will return that node as the lowest common ancestor because it is the lowest common ancestor of p and q in the left subtree of the current node
           return left;
        }
        else{
            return root;  // if both left and right are not null then it means that p and q are found in the left and right subtree of the current node respectively, so the current node is the lowest common ancestor of p and q because it is the lowest node in the tree that has both p and q as its descendants
        }
    }
};