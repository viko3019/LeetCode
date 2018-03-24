/*
  for set of length n there are 2^n possible subset
  
  Algorithm 1- 
    for i 0 to 2^n 
       find all setbit position of i and get all value at those position in original array
       Time Complexity: O(n2^n)
  
*/

class Solution {
public:
    
    int power(int a, int b)
    {
        int pow = 1;
        while ( b ) 
        {
            if ( b & 1 ) 
            {
                pow = pow * a;
                --b;
            }
            a = a*a;
            b = b/2;
        }
        return pow;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>>ans;
        if(len == 0){
            return ans;
        }
        int subsetCount = power(2,len);
        for(int i=0;i<subsetCount;i++){
            vector<int>temp;
            if(i == 0){
                ans.push_back(temp);
            }
            else{
                for(int j = 0; j < len; j++)
                {
                    /* Check if jth bit in the counter is set
                    If set then pront jth element from set */
                    if(i & (1<<j)){
                        temp.push_back(nums[j]);
                    }
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};