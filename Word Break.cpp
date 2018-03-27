/*
We use a boolean vector dp[]. dp[i] is set to true if a valid word (word sequence) ends there. The optimization is to look from current position i back and only substring and do dictionary look up in case the preceding position j with dp[j] == true is found.
*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = wordDict.size();
        if(len == 0){
            return false;
        }
        vector<bool>dp(s.size()+1,false);
        dp[0] = true;
        for(int i=1;i<=s.size();i++){
            for(int j=i-1;j>=0;j--){
                if(dp[j] == true){
                    string word = s.substr(j,i-j); //start index,length
                    if (find(wordDict.begin(), wordDict.end(), word) != wordDict.end()){
                        dp[i] = true;
                        break; //next i
                    }
                }
            }
        }
        return dp[s.size()];
    }
private:
    bool wordBreakRec(string s, vector<string>& wordDict){
        int sz = s.size();
        if(sz == 0){
            return true;
        }
        for(int i=1;i<=sz;i++){
            string word = s.substr(0,i);
            if (find(wordDict.begin(), wordDict.end(), word) != wordDict.end()){
                return wordBreakRec(s.substr(i,sz-i))
            }
        }
        return false;
    }
};