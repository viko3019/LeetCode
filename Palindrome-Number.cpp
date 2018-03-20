class Solution {
public:
    
    int reverse(int x) {
        int temp = 0;
        while(x>0){
            int rem = x%10;
            temp = temp*10 + rem;
            x = x/10;
        }
        return temp;
    }
    
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int temp = reverse(x);
        if(x == temp){
            return true;
        }
        else {
            return false;
        }
    }
    
};