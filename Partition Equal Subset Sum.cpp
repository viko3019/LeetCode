class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int len = nums.size();
        int total = 0;
        for(int i=0;i<len;i++){
            total +=nums[i];
        }
        if(total%2){
            return false;
        }
        int W = total/2;
        int dp[len+1][W+1]; // K[i][j] = true if we can make sum of j by using i elements
        for(int i=0;i<=len;i++) dp[i][0] = true;
        for(int i=1;i<=W;i++) dp[0][i] = false;
        for(int i=1;i<=len;i++){
            for(int j=1;j<=W;j++){
                if(nums[i-1]<=j){
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        // for(int i=0;i<=len;i++){
        //     for(int j=0;j<=W;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[len][W];
    }
};