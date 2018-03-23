/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 
 Time complexity : O(m). A total of mm nodes need to be traversed. Here, mm represents the minimum number of nodes from the
 two given trees.
 Space complexity :O(m). The depth of the recursion tree can go upto mm in the case of a skewed tree. In average case, depth
 will be O(logm).
 
*/
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == NULL){
            return t2;
        }
        if(t2==NULL){
            return t1;
        }
        t1->val = t1->val + t2->val;
        t1->left = mergeTrees(t1->left,t2->left);
        t1->right = mergeTrees(t1->right,t2->right);
        return t1;
    }
};