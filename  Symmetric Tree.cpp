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
    
    bool isMirror(TreeNode* left, TreeNode* right){
        if(left == NULL && right == NULL){
            return true;
        }
        if(left && right && left->val == right->val ){
             return isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
        }
        return false;
    }
    
    bool isSymmetric(TreeNode* root) {
        return isMirror(root,root);
    }
};