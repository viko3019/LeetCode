/*
  Algorithm 1- The brute force approach is based on recursion. We need to try to put both the + and - symbols at every location 
  in the given numsnums array and find out the assignments which lead to the required result SS.
   Time O(2^n),Space complexity : O(n). The depth of the recursion tree can go upto n.
   
  Algorithm 2 - We can optimize algo 1 by using memorization .
  Time complexity : O(l*n). The memomemo array of size l*n has been filled just once. Here, l refers to the range of 
  sum and n refers to the size of numsnums array.
  Space complexity : O(n). The depth of recursion tree can go upto nn.
  
  
*/

class Solution {
public:
    int ans = 0;
    
    void approach1(vector<int>& nums, int pos, int cur, int S){
        if(pos==nums.size() ){
            if(cur==S){
                ans++;
            }
            return;
        }
        approach1(nums, pos+1, cur+nums[pos], S);
        approach1(nums, pos+1, cur-nums[pos], S);
    }
    
    int approach2(vector<int>& nums, int i, int sum, int S, int memo[][2001]){
        if (i == nums.size()) {
            if (sum == S)
                return 1;
            else
                return 0;
        } else {
            if (memo[i][sum + 1000] != INT_MIN) {
                return memo[i][sum + 1000];
            }
            int add = approach2(nums, i + 1, sum + nums[i], S, memo);
            int subtract = approach2(nums, i + 1, sum - nums[i], S, memo);
            memo[i][sum + 1000] = add + subtract;
            return memo[i][sum + 1000];
        }
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        //approach1(nums,0,0,S);
        //return ans;
        
        int len = nums.size();
        int memo[len][2001];
        for(int i=0;i<len;i++){
            for(int j=0;j<2001;j++)
                memo[i][j] = INT_MIN;
        }
        return approach2(nums,0,0,S,memo);
    }
};