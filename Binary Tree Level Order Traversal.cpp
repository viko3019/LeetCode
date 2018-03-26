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
    vector<vector<int>>ans;
    
    void getLevelOrderTraversal(vector<TreeNode*>nodes){
        if(nodes.size()<=0){
            return;
        }
        vector<int>temp1;
        vector<TreeNode*>temp2;
        for(int i=0;i<nodes.size();i++){
           if(nodes[i]){
               temp1.push_back(nodes[i]->val);
               if(nodes[i]->left){
                   temp2.push_back(nodes[i]->left);
               }
               if(nodes[i]->right){
                   temp2.push_back(nodes[i]->right);
               }
           }    
        }
        if(temp1.size()>0){
           ans.push_back(temp1);
        }
        getLevelOrderTraversal(temp2);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(root == NULL){
            return ans;
        }
        vector<TreeNode*>temp;
        temp.push_back(root);
        getLevelOrderTraversal(temp);
        return ans;
    }
};