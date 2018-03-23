/*
   Method 1 - create another array and sort them, now traverse then original array from both the end(ex. i=0 j=len-1 ) and 
   for each index match the value with sorted array if it is not matched then just return diff of i and j;
   Time complexity O(NlogN) space O(N)
   
   Method 2- Using Selection sort algorithm concept. time O(N^2) and space O(1)
   
   Method 3 - we can reduce time for method 2 by using stack to store the value in asscending order and whenever for i<j if 
   stc.top>nums[j]..keep poping from stc...and if we we poped k element then it means nums[j] is k+1 distance away from its 
   actual position.. using this concept we will find startIndex and endIndex. StartIndex is the first indexed that doesn't 
   hold the value in sorted order, and same for endIndex it the first indexed from right side that does not contains value 
   in sorted order
   Time O(N) and space will be O(N)
   
   Method 4- 
      step1 -get the min value for which arr[i]<arr[i-1],here mn = min(mn, arrp[i]) -find lowest value that are not in proper idx
      step2 -get mx for which arr[i]> arr[i+1] mx = max(mx,arr[i]).find largest value that are not in proper idx
      step3 -get the insertion position for mn to make the array in sorted order
      step4 -get the insertion position for mx to make th array in sorted order
      
      
      int findUnsortedSubarray(int[] nums) {
        int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;
        boolean flag = false;
        //step1
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] < nums[i - 1])
                flag = true;
            if (flag)
                min = Math.min(min, nums[i]);
        }
        //step 2
        flag = false;
        for (int i = nums.length - 2; i >= 0; i--) {
            if (nums[i] > nums[i + 1])
                flag = true;
            if (flag)
                max = Math.max(max, nums[i]);
        }
        int l, r;
        //step 3
        for (l = 0; l < nums.length; l++) {
            if (min < nums[l])
                break;
        }
        for (r = nums.length - 1; r >= 0; r--) {
            if (max > nums[r])
                break;
        }
        return r - l < 0 ? 0 : r - l + 1;
    }
      
*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int len = nums.size();
        vector<int>copyArr(len);
        for(int i=0;i<len;i++)
            copyArr[i] = nums[i];
        sort(copyArr.begin(),copyArr.end());
        int startIndex = 0;
        int endIndex = len-1;
        int ans = 0;
        while(startIndex<=endIndex){
            if(copyArr[startIndex] != nums[startIndex] && copyArr[endIndex] != nums[endIndex]){
                //cout<<endIndex<<" "<<startIndex;
                ans = (endIndex-startIndex)+1;
                break;
            }
            if(copyArr[startIndex] == nums[startIndex]) {
                startIndex++;
            }
            if(copyArr[endIndex] == nums[endIndex]){
                endIndex--;
            }
        }
        return ans;
    }
};