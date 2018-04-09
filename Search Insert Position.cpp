class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return bsearch(nums,target);
    }
private:
    int bsearch(vector<int>&nums, int target){
        int len = nums.size();
        int low = 0;
        int high = len-1;
        while(low<=high){
            int mid = (low+high)/2;
            //cout<<low<<" "<<high<<" "<<mid<<endl;
            if(nums[low]>=target){
                return low;
            }
            else if(nums[high]<target){
                return high+1;
            }
            else if(nums[high] == target){
                return high;
            }
            else if(high - low <= 1 && nums[high]>target){
                return high;
            }
            else if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid]<target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
    }
};