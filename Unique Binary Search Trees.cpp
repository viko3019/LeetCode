/*

Number of binary search trees = 
                     (Number of ways root can be choosen)*
                     (Number of Left binary search sub-trees) *                 
                     (Number of Right binary search sub-trees)   
                     
for i-th element as the root, i-1 elements on the left and n-i on the right.

These sub-trees are also BSTs so we can write :

C(n) = C(0)C(n-1) + C(1)C(n-2) + .....+ C(i-1)C(n-i)..... + C(n-1)C(0)   - this is catlan number

SO Using catlan number we can solve -

1) Count the number of expressions containing n pairs of parentheses which are correctly matched. For n = 3, possible expressions are ((())), ()(()), ()()(), (())(), (()()).

2) Count the number of possible Binary Search Trees with n keys (current problem)

3) Count the number of full binary trees (A rooted binary tree is full if every vertex has either two children or no children) with n+1 leaves

*/

class Solution {
public:
    
    int numTrees(int n) {
        
    
        // Table to store results of subproblems
    
        int catalan[n+1];
 

        // Initialize first two values in table
    
        catalan[0] = catalan[1] = 1;
 
    
        // Fill entries in catalan[] using recursive formula
    
        for (int i=2; i<=n; i++)
    
        {
       
            catalan[i] = 0;
        
            for (int j=0; j<i; j++)
            
                catalan[i] += catalan[j] * catalan[i-j-1];
    
        }
 

        // Return last entry
    
        return catalan[n];
    }
};