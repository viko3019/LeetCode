class Solution {
public:
    //using xor method
    int singleNumber(vector<int>& nums) {
        int len = nums.size();
        int res = nums[0];
        for(int i=1;i<len;i++){
            res = res ^ nums[i];
        }
        return res;
    }
};