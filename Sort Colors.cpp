class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        if(len<=1){
            return;
        }
        int low = 0, mid = 0, high = len-1;
        // basically low is pointing upper bound of 0 and high is pointing lower bound of 2..mid is used to traverse between them
        while(mid<=high){
            switch(nums[mid]){
                case 0:
                    swap(nums[low++],nums[mid++]);
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(nums[mid],nums[high--]);
                    break;
            }
        }
    }
};