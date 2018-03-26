class Solution {
public:
    int m = 0;
    int n = 0;
    bool visited[1001][1001];
    
    bool isSafe(vector<vector<char>>& grid,int i, int j){
         return (i >= 0) && (i < m) &&     
           (j >= 0) && (j < n) &&      
           (grid[i][j]=='1' && !visited[i][j]); 
    }
   
    void visitConnectedIsland(vector<vector<char>>& grid,int i, int j){
        int xDir[] = {1, -1, 0, 0};
        int yDir[] = {0, 0, 1, -1}; 
        visited[i][j] = true;
        for (int k = 0; k < 4; ++k){
            if (isSafe(grid, i + xDir[k], j + yDir[k]) ){
                visitConnectedIsland(grid, i + xDir[k], j + yDir[k]);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        if(m==0){
            return 0;
        }
        n = grid[0].size();
        memset(visited,0,sizeof(visited));
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    visitConnectedIsland(grid,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};