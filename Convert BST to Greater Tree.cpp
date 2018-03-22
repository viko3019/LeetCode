/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 
  Method 1- O(N^2) traverse earch node and for search node find sum of value that are greater than current node value 
  
  Method 2- create arr of values of tree , sort them and create a dp(dp[i] will store sum of i to end), now again traverse the  tree find index of current node in sorted array, and update the value using dp.
  so creating arr and dp will take O(2N) space and O(2N) time complexity, and for sorting O(NlogN)..traversing tree and updating value will take O(NlogN)...
  so basically this algo will take O(N) space and O(NlogN) time.
  
  Method 3 - The idea is to traverse BST in reverse inorder. Reverse inorder traversal of a BST gives us keys in decreasing order. Before visiting a node, we visit all greater nodes of that node. While traversing we keep track of sum of keys which is the sum of all the keys greater than the key of current node.
 */
class Solution {
public:
    
    // A recursive function that traverses the given BST in reverse inorder and
    // for every key, adds all greater keys to it
    void addGreaterUtil(TreeNode *root, int *sum_ptr)
    {
       // Base Case
       if (root == NULL)
          return;
 
       // Recur for right subtree first so that sum of all greater
       // nodes is stored at sum_ptr
       addGreaterUtil(root->right, sum_ptr);
 
       // Update the value at sum_ptr
       *sum_ptr = *sum_ptr + root->val;
 
       // Update key of this node
       root->val = *sum_ptr;
 
       // Recur for left subtree so that the updated sum is added
       // to smaller nodes
       addGreaterUtil(root->left, sum_ptr);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        addGreaterUtil(root, &sum);
        return root;
    }
};