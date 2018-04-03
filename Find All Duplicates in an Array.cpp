/*
  Approach 1 - O(N^2) space O(1)
  Approach 2 - O(NlogN) sort and traverse,space O(1)
  Approach 3 - using unorder map unorder_map<int,int>ump; ump[num] = count, time O(N) ,space O(1)
  Approach 4 - bcz arr[i] <= length of array .. while traversing mark arr[arr[i]] = arr[arr[i]] *-1,
  now again traverse the array and insert the element into vector if it is >=0.
*/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& temp) {
        vector<int>nums = temp;
        int len = nums.size();
        vector<int>ans;
        if(len == 0){
            return ans;
        }
        for(int i=0;i<len;i++){ 
           int idx = abs(nums[i])-1;
           if(nums[idx]>0){
               nums[idx] = -abs(nums[idx]);
           } 
           else{
               ans.push_back(idx+1);
           } 
        }
        return ans;
    }
};