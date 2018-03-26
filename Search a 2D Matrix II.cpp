/*
  Aproach 1 - O(MlogN) for each row do binary search
  Aproach 2 - O(M+N) intially pointing at 0'th row and last col lets say matrix[i][j] if it is greater than target value then we 
  need to move to left side(j--) but if matrix[i][j] is less than target value then we need to move downwards.
*/
class Solution {
public:
    
    bool searchMatrixAlgo2(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        int i = 0, j = n - 1;
        while (i < m && j >= 0) {
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] > target) {
                j--;
            } else 
                i++;
        }   
        return false;   
    }
    
    bool searchMatrixAlgo1(vector<vector<int>>& matrix, int target) { // O(M+N)
        int len = matrix.size();
        if(len == 0){
            return false;
        }
        int col = matrix[0].size();
        if(col == 0){
            return false;
        }
        for(int i=0;i<len;i++){
            if(matrix[i][0]>target){
                return false;
            }
            if(binary_search (matrix[i].begin(), matrix[i].end(), target)){
                return true;
            }
        }
        return false;
    }
    
     bool searchMatrix(vector<vector<int>>& matrix, int target) {
         
         //return searchMatrixAlgo1(matrix,target);
         return searchMatrixAlgo2(matrix,target);
     }
};