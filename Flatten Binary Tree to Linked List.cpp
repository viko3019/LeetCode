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
    
    void algo1(TreeNode * root){
        if(root == NULL){
            return;
        }
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        root->left = NULL;
        algo1(left);
        algo1(right);
        root->right = left;
        TreeNode *current = root;
        while(current->right!=NULL){
            current = current->right;
        }
        current->right = right;
    }
    
    void algo2(TreeNode *root){
        if (root == NULL) {
            return;
        }
        if (root->left == NULL && root->right == NULL) {
            return;
        }
        while (root != NULL) {
            if (root->left == NULL) {
                root = root->right;
                continue;
            }
            TreeNode *left = root->left;
            while (left->right != NULL) {
                left = left->right;
            }
            left->right = root->right;
            root->right = root->left;
            root->left = NULL;
            root = root->right;
        }
    }
    
    void flatten(TreeNode* root) {
        if(root == NULL){
            return;
        }
        //algo1(root);
        algo2(root);
    }
};