/*
   Approach 1 - O(N^2) and space O(1) ..for each number find that it is duplicate or not
   Approach 2- use map to strore the freq of number and then traverse the array and return the element having freq more than 1
               Time - O(NlogN)(if we are using ordered map and if we use unordered map it will be O(N)) but space O(N)
   Approach 3 - sort the array, and traverse the array if arr[i+1] == arr[i] return arr[i]        
                Time O(NlogN) but original array is modified
   Approach 4 - traverse the array and mark nums[nums[i]-1] = -1 but return nums[i] if it is already marked as -1
                Time O(N) space O(1) - original array modified
                
   Approach 5- using linked list cycle concept
   
   Use two pointers the fast and the slow. The fast one goes forward two steps each time, while the slow one goes only step each 
   time. They must meet the same item when slow==fast. In fact, they meet in a circle, the duplicate number must be the entry 
   point of the circle when visiting the array from nums[0]. Next we just need to find the entry point. We use a point(we can use 
   the fast one before) to visit form begining with one step each time, do the same job to slow. When fast==slow, they meet at 
   the entry point of the circle.
   Time O(N) space O(1)
   
   Approach 6 - using binary search concept
   At first the search space is numbers between 1 to n. Each time I select a number mid (which is the one in the middle) and 
   count all the numbers equal to or less than mid. Then if the count is more than mid, the search space will be [1 mid] 
   otherwise [mid+1 n]. I do this until search space is only one number.
   Time O(NlogN) space O(1)
                
*/

class Solution {
public:
    
    int approach3(vector<int>& nums){ // but in this approach original array is modified
        sort(nums.begin(),nums.end());
        int len = nums.size();
        for(int i=1;i<len;i++){
            if(nums[i] == nums[i-1]){
                return nums[i];
            }
        }
    }
    
    int approach5(vector<int>& nums){
        if (nums.size() > 1)
        {
            int slow = nums[0];
            int fast = nums[nums[0]];
            while (slow != fast)
            {
                slow = nums[slow];
                fast = nums[nums[fast]];
            }
            fast = 0;
            while (fast != slow)
            {
                fast = nums[fast];
                slow = nums[slow];
            }
            return slow;
        }
        return -1;
    }
    
    int notGreaterThan(vector<int>& nums, int target) {
        int cnt = 0;
        for (int num : nums)
            if (num <= target)
                cnt++;
        return cnt;
    }
    
    int approach6(vector<int>& nums){
        int n = nums.size(), l = 1, r = n - 1;
        while (l < r) {
            int m = l + ((r - l) >> 1);
            int cnt = notGreaterThan(nums, m);
            if (cnt <= m) l = m + 1;
            else r = m;
        } 
        return l;
    }
    
    
    
    int findDuplicate(vector<int>& nums) {
        // return approach3(nums);
       // return approach5(nums);
        return approach6(nums);
    }
};