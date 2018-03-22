/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 
  Method 1- for each subtree calculate sum of substree, and if it is matched to given number then increament your ans,T-O(N^2) 
  Method 2- Traverse tree and store the sum of subtree in map time O(N) , space O(N)
 
 */
class Solution {
public:
    int ans = 0;
    int helper(TreeNode* root, int sum, int total) {
        if (root == NULL)
            return 0;
        else {
            total += root->val;
            int count = sum == total ? 1 : 0;
            count += helper(root->left, sum, total);
            count += helper(root->right, sum, total);
            return count;
        }
    }
    
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return 0;
        else {
            int count = helper(root, sum, 0);
            return count + pathSum(root->left, sum) + pathSum(root->right, sum);
        }
        
    }
};