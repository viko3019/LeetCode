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
    
    // we can optimize this alogirthm to store the idx of inorder value in map to reduce the time complexity
    TreeNode* treeCreation(vector<int>& preorder, vector<int>& inorder,int startP,int endP, int startI, int endI){
        if(startP>=endP || startI >= endI){
            return NULL;
        }
        int val = preorder[startP];
        auto f = find(inorder.begin() + startI, inorder.begin() + endI, val);
        int dis = f - inorder.begin() - startI;
        
        TreeNode *root = new TreeNode(val);
        root->left = treeCreation(preorder, inorder, startP+1, startP+1+dis, startI, startI+dis);
        root->right = treeCreation(preorder, inorder, startP+1+dis, endP, startI+dis+1 , endI);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return treeCreation(preorder, inorder, 0, preorder.size(), 0, inorder.size());
    }
};