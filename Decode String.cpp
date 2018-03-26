/*

Method 1: DFS recursion. During recursion, every returned result is the decoded substring in a complete “[]”. Scan the string, the char can only be number or letter, if it is letter, save the letter to the result string. If it is number, get the complete number. Then next char must be ‘[’, so we increase the i pointer, do recursion to the rest of the string. Notice that the base case of the recursion is the end of the string or s[i] != ‘]’. 

Method 2: Two stacks, one for numbers, one for letters. Scan the string, if it is number, get the complete number as cnt, if it is ‘[’, push the number and current result to their corresponding stacks and reset cnt and result. If it is ‘]’, get the cnt from number stack and update the top string of letter stack with cnt, update the result string with top string from letter stack and pop letter stack. Else append the current letter to the result. 

*/

class Solution {
public:
    string Method1(string s, int &i){
        int n = s.size();
        string res = "";
        while(i<n && s[i] != ']'){
            if (isalpha(s[i])) {
                res += s[i++];
            }
            else {
                int cnt = 0;
                while(i<n && isdigit(s[i])){
                    cnt = cnt*10 + s[i++]-'0';
                }
                i++;//for ]
                string temp = Method1(s,i);
                i++;
                while(cnt>0){
                    res +=temp;
                    cnt--;
                }
            }
        }
        //cout<<res<<" ";
        return res;
    }
    
    string Method2(string s){
        int n = s.size();
        string res = "";
        stack<int> num;
        stack<string> str;
        int cnt = 0;
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                cnt = cnt*10 + s[i]-'0';
            }
            else if(s[i] == '['){
                num.push(cnt);
                str.push(res);
                cnt = 0;
                res.clear();
            }
            else if(s[i] == ']'){
                int k = num.top();
                num.pop();
                while (k-- > 0) {
                    str.top() += res;
                }
                res = str.top();
                str.pop();
            }
            else{
                res +=s[i];
            }
        }
        return res;
    }
    
    string decodeString(string s) {
        //int i = 0;
        //return Method1(s, i);
        return Method2(s);
    }
};