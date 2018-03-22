/*
   Method 1- O(N^2) for every number from 1 to N search that element is present in array or not
   Method 2- Create a Map(un_ordered map or hashMap) and then for each number 1 to n check in hash Time O(N) ans space O(N)
   Method 2 - Traverse the array and mark arr[abs(arr[i])-1] = -arr[arr[i]] if this is positive, now traverse again and return all index of array that having positive nbr  Time O(N) and space O(1)
*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        for(int i=0;i<len;i++){
            int idx = abs(nums[i])-1;
            if(nums[idx]>0){
                nums[idx] = - nums[idx];
            }
        }
        vector<int>ans;
        for(int i=0;i<len;i++){
            //cout<<nums[i]<<" ";
            if(nums[i]>=0){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};