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
    
    int getRobbedValue(TreeNode*  root,bool flag){ //flag true - means he can rob curr node otherwise not
        if(root == NULL){
            return 0;
        }
        if(flag){
            return root->val + getRobbedValue(root->left,false) + getRobbedValue(root->right,false);
        }
        else{
            int ans1 = getRobbedValue(root->left,true) + getRobbedValue(root->right,true);
            int ans2 = getRobbedValue(root->left,true) + getRobbedValue(root->right,false);
            int ans3 = getRobbedValue(root->left,false) + getRobbedValue(root->right,true);
            int ans4 = getRobbedValue(root->left,false) + getRobbedValue(root->right,false);
            return max(max(ans1,ans2),max(ans3,ans4));
        }
    }
    
    int approach1(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        if(root->left == NULL && root->right == NULL){
            return root->val;
        }
        int ans1 = getRobbedValue(root,true);//if root node considered
        int ans2 = getRobbedValue(root,false);//root node is not considered
        //cout<<ans1<<" "<<ans2<<endl;
        return max(ans1,ans2);
    }
    
    int approach2(TreeNode* root){ //optimized approach of approach1 - by removing unnecessary calls
        //the time complexity turns out to be exponential
        if (root == NULL) return 0;
        int val = 0; 
        if (root->left != NULL) {
            val += approach2(root->left->left) + approach2(root->left->right);
        }
        if (root->right != NULL) {
            val += approach2(root->right->left) + approach2(root->right->right);
        }
        return max(val + root->val, approach2(root->left) + approach2(root->right));
    }
    
    //approach 3 - optimizing approach 2 by using map
    
    int approach3(TreeNode* root, map<TreeNode*,int>mp){ //Time O(N) space O(N)
        if (root == NULL) return 0;
        if(mp[root]){
            return mp[root];
        }
        int val = 0; 
        if (root->left != NULL) {
            val += approach2(root->left->left) + approach2(root->left->right);
        }
        if (root->right != NULL) {
            val += approach2(root->right->left) + approach2(root->right->right);
        }
        mp[root] = max(val + root->val, approach2(root->left) + approach2(root->right));
        return mp[root];
    }
    
    //approach 4 - to reduce recursion cost
    
    vector<int> approach4(TreeNode* root){
        if (root == NULL) {
            return vector<int>(2,0);
        }
        vector<int> left = approach4(root->left);
        vector<int> right = approach4(root->right);
        vector<int> res(2,0);
        res[0] = max(left[0], left[1]) + max(right[0], right[1]);
        res[1] = root->val + left[0] + right[0];
        return res;
    }
    
    int rob(TreeNode* root) {
        //return approach1(root); //tle for each false there are 4 option 
        //return approach2(root);
       // map<TreeNode*,int>temp;
       // return approach3(root,temp);
       vector<int> res = approach4(root);
       return max(res[0], res[1]); 
        
    }
};