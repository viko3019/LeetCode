class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        //  for all negative case 
        int mx = INT_MIN;
        for(int i=0;i<len;i++){
            mx = max(mx,nums[i]);
        }
        if(mx<0){
            return mx;
        }
        int dp[len];
        if(nums[0]< 0){
            dp[0] = 0;
        }
        else dp[0] = nums[0];
        int ans = dp[0];
        for(int i=1;i<len;i++){
            if(dp[i-1]+ nums[i]<0){
                dp[i] = 0;
            }
            else {
                dp[i] = dp[i-1]+nums[i];
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};