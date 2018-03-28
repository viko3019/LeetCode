/*
   approach 1- sort and for each i and j search of -(nums[i]+nums[j]) using binary search time complexity O(N^2logN)
   approach 2 - map each value with their indexes, now for i,j check -(nums[i]+nums[j]) in map if present add to the list
   using unordered_map Time complexity O(N^2) - bcz searching is O(1) but space is O(N)
   
   approach 3 - we can optimize approach 2 by sorting and two pointer concept
   
   
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>>ans;
        if(len <=2) return ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<len;i++){
            int j = i+1;
            int k = len-1;
            int temp = nums[i];
            while(j<k){
                int temp1 = nums[j];
                int temp2 = nums[k];
                if(nums[i]+nums[j]+nums[k] == 0){
                    vector<int>v;
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                    v.push_back(nums[k]);
                    ans.push_back(v);
                    
                    while(nums[j] == temp1) j++;
                    while(nums[k] == temp2) k--;
                }
                else if(nums[i]+nums[j]+nums[k]<0){
                    j++;
                }
                else{
                    k--;
                }
            }
            // Processing duplicates of Number 1
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) 
                i++;

        }
        return ans;
    }
};