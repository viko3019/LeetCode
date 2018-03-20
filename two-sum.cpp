class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        pair<int,int>p[len];
        for(int i=0;i<nums.size();i++){
            p[i].first = nums[i];
            p[i].second = i;
        }
        sort(p,p+len);
        int i = 0;
        int j = len-1;
        vector<int> ans(2);
        while(i<j){
           // cout<<i<<" "<<j<<endl;
            if(p[i].first+p[j].first == target){
                ans[0] = p[i].second;
                ans[1] = p[j].second;
                break;
            }
            else if(p[i].first+p[j].first>target){
                j--;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};