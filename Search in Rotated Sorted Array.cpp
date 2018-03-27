/*
  Approach 1 - find min element index, then according to min element index check that target element is present in left half or 
  right half and then perform binarysearch on that half.
  
  Approach 2 - we can do this in on pass of binary search
  
  1) Find middle point mid = (l + h)/2
  2) If key is present at middle point, return mid.
  3) Else If arr[l..mid] is sorted
    a) If key to be searched lies in range from arr[l]
       to arr[mid], recur for arr[l..mid].
    b) Else recur for arr[mid+1..r]
  4) Else (arr[mid+1..r] must be sorted)
    a) If key to be searched lies in range from arr[mid+1]
       to arr[r], recur for arr[mid+1..r].
    b) Else recur for arr[l..mid] 
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if(len == 0){
            return -1;
        }
         /* Approach 1*/
//         int low = 0 ;
//         int high = len-1;
//         int pvt =  getPivotIndex(nums,len);
//         if(pvt>=0){
//             if(nums[0]<=target && nums[pvt-1]>=target){
//                 return binarySearch(nums,low,pvt,target);
//             }
//             else if(nums[high]>=target && nums[pvt]<=target){
//                 return binarySearch(nums,pvt,high,target);
//             }
//             else{
//                 return -1;
//             }
//         }
//         else{
//             return -1;
//         }
        
        /*approach 2*/
        return approach2(nums,0,len-1,target);
    }
private:
    int getPivotIndex(vector<int>& nums,int len){
        int low = 0;
        int high = len-1;
        if(low == high){ // one length
            return low;
        }
        if(nums[low]<nums[high]){ //case - not rotated
            return low;
        }
        while(low<=high){
            int mid = (low+high)/2;
            if (mid < high && nums[mid] > nums[mid + 1]){ // if num[mid] >num[mid+1] then mid+1 is pvt 
                 return mid+1;
            }
            if (mid > low && nums[mid] < nums[mid - 1]){ // if num[mid]< num[mid-1] then mid is pvt
                return (mid);
            }
            else if(nums[mid]>nums[low]){ // if left part of mid is sorted then choose right part
                low = mid+1;
            }
            else{ // if right part of mid is sorted then choose left part
                high = mid-1;
            }
        }
        return -1;
    }
    
    int binarySearch(vector<int>& nums, int low, int high,int target){
       
        if(low>high) return -1;
        if(low == high && nums[low] == target){
            return low;
        }
        //cout<<low<<" "<<high<<endl;
        while(low<=high){
            int mid = (low+high)/2;
          //  cout<<mid;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid]>target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return -1;
    }
    
    int approach2(vector<int>&nums,int low,int high,int target){
        if(low>high){
            return -1;
        }
        int mid = (low+high)/2;
        if(nums[mid] == target){
            return mid;
        }
        else if(nums[low] <= nums[mid]){ //low to mid is sorted
            if(target>=nums[low] && target<=nums[mid]){
                return approach2(nums,low,mid-1,target);
            }
            else{
                 return approach2(nums,mid+1,high,target);
            }
        }
        else{ // otherwise right part is sorted
            if(target>=nums[mid+1] && target<=nums[high]){
                 return approach2(nums,mid+1,high,target);
            }
            else{
                 return approach2(nums,low,mid-1,target);
            }
        }
    }
};