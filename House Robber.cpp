/*
  DP
  dp[i] = max(if we are considering i'th item , if we are not considering i'th item)
  dp[i] = max(nums[i]+dp[i-2], dp[i-1]);
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len == 0){
            return 0;
        }
        if(len == 1){
            return nums[0];
        }
        int dp[len];
        dp[0] = nums[0]; // if len == 1
        dp[1] = max(nums[0],nums[1]); // if len == 2
        for(int i = 2; i<len; i++){
            dp[i] = max(nums[i]+dp[i-2], dp[i-1]); // ans till i
        }
        return dp[len-1];
    }
};