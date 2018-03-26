/* O NlogN approach
we have set of active lists of varying length. We are adding an element A[i] to these lists. We scan the lists (for end elements) in decreasing order of their length. We will verify the end elements of all the lists to find a list whose end element is smaller than A[i] (floor value).

Our strategy determined by the following conditions,

1. If A[i] is smallest among all end 
   candidates of active lists, we will start 
   new active list of length 1.
2. If A[i] is largest among all end candidates of 
  active lists, we will clone the largest active 
  list, and extend it by A[i].

3. If A[i] is in between, we will find a list with 
  largest end element that is smaller than A[i]. 
  Clone and extend this list by A[i]. We will discard all
  other lists of same length as that of this modified list.
*/

class Solution {
public:
    
    int algorithm1(vector<int>&nums){ //O(N^2)
        int len = nums.size();
        if(len<=1){
            return len;
        }
        int lisDp[len];
        for(int i=0;i<len;i++) lisDp[i] = 1;
        int ans = 1;
        for(int i=1;i<len;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && lisDp[i]< lisDp[j]+1){
                    lisDp[i] = lisDp[j]+1;
                    ans = max(lisDp[i],ans);
                }
            }
        }
        return ans;
    }
    
    int algorithm2(vector<int>&nums){
        vector<int> res;
        for(int i=0; i<nums.size(); i++) {
            auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
            if(it==res.end()) res.push_back(nums[i]);
            else *it = nums[i];
        }
        return res.size();
    }
    
    int lengthOfLIS(vector<int>& nums) {
        //return algorithm1(nums);
        return algorithm2(nums);
    }
};