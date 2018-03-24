class Solution {
public:
    
    void generateAllValidComination(int leftP, int rightP, string str,vector<string>&ans){
        if(leftP == 0 && rightP == 0){
            ans.push_back(str);
            return;
        }
        if(leftP){
            generateAllValidComination(leftP-1,rightP,str+"(",ans);
        }
        if(leftP<rightP){
            generateAllValidComination(leftP,rightP-1,str+")",ans);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        generateAllValidComination(n,n,"",ans);
        return ans;
    }
};