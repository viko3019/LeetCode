class Solution {
public:
    bool isValid(string s) {
        int len = s.length();
        stack<int>stc;
        for(int i = 0; i< len; i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                stc.push(s[i]);
            }
            else if(stc.size() == 0){
                return false;
            }
            else if(s[i] == ')' && stc.top() != '('){
                return false;
            }
            else if(s[i] == '}' && stc.top() != '{'){
                return false;
            }
            else if(s[i] == ']' && stc.top() != '['){
                return false;
            }
            else {
                stc.pop();
            }
        }
        if(stc.size() == 0){
            return true;
        }
        else {
            return false;
        }
    }
};