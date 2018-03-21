/*
   Possible solution
   
   Method 1 - O(N^2) for each element count its freq and check for majority element
   Method 2- sort the array O(NlogN) then find majority element by traversing the sorted array
   Method 3- map O(NlogN) for creating map for all the element and while creating map we can store majority element, space O(N)
   Method 4- using unordered_map or hashmap time O(N) and space is also O(N)
   Method 5- Using Moore’s Voting Algorithm . Time O(N) space is O(1)
   Moore’s Voting Algorithm -
   findCandidate(a[], size)
    1.  Initialize index and count of majority element
        maj_index = 0, count = 1
    2.  Loop for i = 1 to size – 1
          (a) If a[maj_index] == a[i]
                 count++
         (b) Else
                count--;
         (c) If count == 0
              maj_index = i;
              count = 1
    3.  Return a[maj_index]
   
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        int majorityIndex = 0;
        int count = 1;
        for(int i=1;i<len;i++){
            if(nums[i] == nums[majorityIndex]){
                count++;
            }
            else{
                count --;
            }
            if(count == 0){
                majorityIndex = i;
                count = 1;
            }
        }
        return nums[majorityIndex];
    }
};