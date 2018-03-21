/*
  Method1 - using another array , Time O(N) but space is also O(N)
  Method2 - let startindex = first 0 index, nextIndex = 1, now for nextIndex -> end if any non zero encountered swap them with startIndex  value and startIndex will be next zero value index

*/

class Solution {
public:
    
    int getNextZeroIndex(vector<int>nums,int currIdx){
        while(nums[currIdx] != 0 ){
            currIdx++;
        }
        return currIdx;
    }
    
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        if(len<=1){
            return;
        }
        int i = getNextZeroIndex(nums,0);
        int j = 1;
        while(i<len && j<len){
            if(nums[j] != 0 && i<j){
                int temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
                i = getNextZeroIndex(nums,i+1);
            }
            j++;
        }
    }
};