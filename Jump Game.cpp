/*
   approach 1 - O(n^2) create a dp... where dp[i] represent that is possible to reach at i or not,
   for i =0 to len
      if(a[i] == 0 and dp[i] == false) return false;
      int temp = i +a[i];
      for j = i to temp 
         dp[j] = true;
         
   approach 2 - we can optimize this using a little bit observation..we dont need to maintain dp. just maintain max reachable 
   distance.       
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        if(len == 0){
            return false;
        }
        if(nums[0] == 0){
            return len == 1;
        }
        int mx = nums[0];
        for(int i=1;i<len;i++){
            if(nums[i] == 0 && mx<=i && i!=len-1){
                return false;
            }
            mx = max(i+nums[i],mx);
        }
        if(mx>=len-1){
            return true;
        }
        else {
            return false;
        }
    }
};