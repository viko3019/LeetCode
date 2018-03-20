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
    
    int calDepth(TreeNode* root, int depth){
        if(root == NULL){
            return 0;
        }
        return max(calDepth(root->left,depth+1),calDepth(root->right,depth+1))+1;
    }
    
    int maxDepth(TreeNode* root) {
        return calDepth(root,0);
    }
};