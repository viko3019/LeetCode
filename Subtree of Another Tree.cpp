/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 
   Method 1- Traverse the tree T in preorder fashion. For every visited node in the traversal, see if the subtree rooted with 
   this node is identical to S. Time O(MN) space O(1)
   
   Method 2- Tree S is a subtree of T if both inorder and preorder traversals of S arew substrings of inorder and preorder 
   traversals of T respectively.
   
   Following are detailed steps.
   
   1) Find inorder and preorder traversals of T, store them in two auxiliary arrays inT[] and preT[].
   
   2) Find inorder and preorder traversals of S, store them in two auxiliary arrays inS[] and preS[].
   
   3) If inS[] is a subarray of inT[] and preS[] is a subarray preT[], then S is a subtree of T. Else not
   
   Time Complexity: Inorder and Preorder traversals of Binary Tree take O(n) time. The function strstr() can also be implemented
   in O(n) time using KMP string matching algorithm.
 
 */
class Solution {
public:
    
   bool isSame(TreeNode* s, TreeNode* t) {
        if(s == NULL && t == NULL){
            return true;
        }
        else if(s == NULL && t != NULL){
            return false;
        }
        else if(s !=NULL && t== NULL){
            return false;
        }
        else if(s->val == t->val && isSame(s->left,t->left) && isSame(s->right , t->right)){
            return true;
        }
        else{
            return false;
        }
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s == NULL){
            return false;
        }
        else if(isSame(s,t)){
            return true;
        }
        else {
            return isSubtree(s->left,t) || isSubtree(s->right,t);
        }
    }
};