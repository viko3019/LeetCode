class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        vector<int>ans;
        ans.push_back(-1);
        ans.push_back(-1);
        if(len == 0){
            return ans;
        }
        auto lb = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        auto ub = upper_bound(nums.begin(),nums.end(),target) - nums.begin();
       // cout<<lb<<" "<<ub;
        if(lb == ub){
            return ans;
        }
        else if(lb<len){
            ans[0] = lb;
            ans[1] = ub-1;
            return ans;
        }
        else
            return ans;
    }
};