/*
  Algorithm 1- create a dp[n][n] ,..dp[i][j] = true if str(i..j) are palindrom otherwise dp[i][j] is false
  initial mark dp[i][i] = true (single char case). 
  now for i = n-2 to 0
     for j = i+1 to n-1
       if it is 2 length substring and it is palindrom mark them them true and increase your ans
       else
          for each substr(i,j) if str[i] == str[j] and dp[i+1][j-1] is already mark then mark dp[i][j] and increase your ans

*/

class Solution {
public:
    
    int countSubstrings(string s) {
        int N = s.length();
        if(N == 0) return 0;
        bool dp[N][N];
        memset(dp,false,sizeof(dp));
        for(int i=0; i<N; i++){
            dp[i][i] = true;
        }
        int count = N;
        for(int i=N-2; i>=0; i--){
            for(int j=i+1; j<N; j++){
                if(j-i<=2 && s[i] == s[j]){
                    dp[i][j] = true;
                    count ++;
                }
                else if(s[i] == s[j] && dp[i+1][j-1]) {
                    dp[i][j] = true;
                    count ++;
                }
                else{
                    //do nothing
                }
            }
        }
        return count;
    }
};