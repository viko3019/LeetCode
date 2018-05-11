class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> S;
        heights.push_back(0); // 
        int res = 0;
        
        for(int i = 0; i<heights.size(); i++)
        {
            if(S.empty() || heights[i] > heights[S.top()])
                S.push(i);
            else
            {
                int temp = S.top(); 
                S.pop();
                int dist = S.empty() ? i : i-S.top() -1;
                res = max(res, dist * heights[temp]);
                i--; // set i one step back.  to make sure the bar i will be processed. 
            }
        }
                          
        return res;
    }
};