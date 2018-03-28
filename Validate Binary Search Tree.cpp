/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 
 Approach 1 - for each node get max value and left subtree and min value in right substree if 
              mx >= root->data || mn <= root-data return false
              otherwise return true
 Approach 2 - we can reduce the time for calculating mn and max value by passing mn and max as parameter     
 
 Approach 3 - do inorder traversal and store in an array if array is a sorted array then return true otherwise return false
 
 Approach 4 - we can optimize approach 3 . we dont need auxilary array to store the elements. bcz in this approach we just need 
 previous visited node
 
 */
class Solution {
public:
    TreeNode* prev = NULL;
    bool isValidBST(TreeNode* root) {
        if(!root){
           return true;
        }
        if (!isValidBST(root->left))
        
            return false;
        // if(prev){
        //     cout<<prev->val<<" "<<root->val;
        // }
        if(prev != NULL && root->val <= prev->val){
            return false;
        }
        prev = root;
        return isValidBST(root->right);
    }
};