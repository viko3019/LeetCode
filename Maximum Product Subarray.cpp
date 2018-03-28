/*
    Aprroach 1  - O(N^2) 
    Approach 2 - O(N) using kadane algorithm
    It is similar to Largest Sum Contiguous Subarray problem. The only thing to note here is, maximum product can also be 
    obtained by minimum (negative) product ending with the previous element multiplied by this element
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        if(len == 0){
            return 0;
        }
        if(len == 1 && nums[0]<=0){
            return nums[0];
        } 
        int maxEnd = 1;
        int minEnd = 1;
        int maxSoFar = INT_MIN;
        for(int i=0;i<len;i++){
            int temp = max(maxEnd,1);
            //case 1 num is positive
            if (nums[i] > 0) {
                maxEnd = temp*nums[i];
                minEnd *= nums[i];
            } else {
                maxEnd = minEnd*nums[i];
                minEnd = temp*nums[i];
            }
            maxSoFar = max(maxSoFar,maxEnd);
        }
        return maxSoFar;
     }
};