class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(p.size()+1, vector<bool>(s.size()+1, false));
        dp[0][0] = true;
        for (int i=1; i <= p.size(); i++)
            dp[i][0] = p[i-1] == '*' ? dp[max(i-2,0)][0] : false;
        for (int i=1; i <= p.size(); i++) {
        for (int j=1; j <= s.size(); j++) {
            if (s[j-1] == p[i-1] || p[i-1] == '.')
                dp[i][j] = dp[i-1][j-1];
            else if (p[i-1] == '*') {
                dp[i][j] = dp[max(i-2, 0)][j] || dp[i][j-1] && (s[j-1] == p[i-2] || p[i-2] == '.');
            }
        }
    }
        return dp.back().back();
    }
};