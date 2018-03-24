/*
 Algorithm 1 - we can use two dp dp1[i] = multiplication start to i, dp2[j] = multiplication from end to j,
 now in result res[i] = dp1[i-1]*dp2[i+1];
 Time O(N), space O(N)
 
 Algorithm2 - we can reduce these two dp by two variable one will hold multiplication from start and otherwill hold 
 multiplication from end.
 Time O(N), space O(1)
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        int startMul = 1;
        int endMul = 1;
        vector<int>ans(len,1);
        for(int i=0;i<len;i++){
            ans[i] *= startMul;
            startMul *= nums[i];
            ans[len-i-1] *= endMul;
            endMul *= nums[len-i-1];    
        }
        return ans;
    }
};