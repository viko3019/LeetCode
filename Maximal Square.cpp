/*
Algorithm:
 Let the given binary matrix be M[R][C]. The idea of the algorithm is to construct an auxiliary size matrix S[][] in which each   
 entry S[i][j] represents size of the square sub-matrix with all 1s including M[i][j] where M[i][j] is the rightmost and 
 bottommost entry in sub-matrix.
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if(row == 0){
            return 0;
        }
        int col = matrix[0].size();
        if(col == 0){
            return  0;
        }
        int dp[row][col];
        int ans=0;
        //copy first row
        for(int i=0;i<col;i++)
        {
            dp[0][i] = matrix[0][i] -'0';
            if(dp[0][i]) ans = 1;
        }
        //copy first col
        for(int i=0;i<row;i++){ 
            dp[i][0] = matrix[i][0] - '0';
            if(dp[i][0]) ans = 1;
        }
        
        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){
                if(matrix[i][j] == '1'){
                    dp[i][j] = min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1])+1;
                }
                else {
                    dp[i][j] = 0;
                }
                ans = max(ans,dp[i][j]);
            }
        }
        return ans*ans;
    }
};