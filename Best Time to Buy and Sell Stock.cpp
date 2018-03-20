class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len <=1){
            return 0;
        }
        stack<int>stc;
        stc.push(prices[0]);
        int ans = 0;
        for(int i=1;i<len;i++){
            if(prices[i]<stc.top()){
                stc.pop();
                stc.push(prices[i]);
            }
            else{
                ans = max(ans,prices[i]-stc.top());
            }
        }
        return ans;
    }
};