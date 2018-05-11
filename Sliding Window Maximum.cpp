class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       
        deque<int>dq(k);
        vector<int>ans;
         int n = nums.size();
        if(n == 0){
            return ans;
        }
        int i=0;
        while(i<k){
            while(!dq.empty() && nums[i]>=nums[dq.back()])
                dq.pop_back();
            dq.push_back(i);
            i++;
        }
        while(i<n){
            ans.push_back(nums[dq.front()]);
            while(!dq.empty() && dq.front() <= i-k){ // window size limit
                dq.pop_front();
            }
            //mainting order
            while(!dq.empty() && nums[i] >= nums[dq.back()]){
                dq.pop_back();
            }
            
            dq.push_back(i);
            i++;
        }
        ans.push_back(nums[dq.front()]);
        return ans;      
    }
};