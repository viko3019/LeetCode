/*
   Using knapsack algorithm
   dp[i][j]  min coin needed to make sum i using j elements, but for this prob we can reduce space complexity, we just need to 
   store dp[i] - min number of coin needed to make sum of i 
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
       int len = coins.size();
       if(amount == 0)  {
           return 0;
       }
      // sort(coins.begin(),coins.end()); 
       vector<int>dp(amount+1,INT_MAX);
       dp[0] = 0;
       for(int i=1;i<=amount;i++){
           for(int j=0;j<len;j++){
               if (coins[j] <= i)
               {
                   int sub_res = dp[i-coins[j]];
                   if (sub_res != INT_MAX && sub_res + 1 < dp[i])
                       dp[i] = sub_res + 1;
               }
           }
       }
       //for(int i=1;i<=amount;i++) cout<<dp[i]<<" ";
       if(dp[amount] == INT_MAX){
           return -1;
       } 
       return dp[amount]; 
    }
};