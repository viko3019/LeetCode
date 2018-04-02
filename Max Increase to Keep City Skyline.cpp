class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        int topBottomMax[col];
        int leftRightMax[row];
        //get top bottom
        for(int i=0;i<col;i++){
            topBottomMax[i] = -1;
            for(int j=0;j<row;j++){
                topBottomMax[i] = max(topBottomMax[i],grid[j][i]);
            }
        }
        
        //get left right
        for(int i=0;i<row;i++){
            leftRightMax[i] = -1;
            for(int j=0;j<col;j++){
                leftRightMax[i] = max(leftRightMax[i],grid[i][j]);
            }
        }
        // for(int i=0;i<col;i++) cout<<topBottomMax[i]<<" ";
        // cout<<endl;
        //  for(int i=0;i<row;i++) cout<<leftRightMax[i]<<" ";
        // cout<<endl;
        //modify the matrix
        int newTotal = 0;
        int originalTotal = 0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                originalTotal += grid[i][j];
                grid[i][j] = min(topBottomMax[j],leftRightMax[i]);
                newTotal = newTotal+ grid[i][j];
                //cout<<grid[i][j]<<" ";
            }
           // cout<<endl;
        }
        return abs(newTotal-originalTotal);    
    }
};