class Solution {
public:
    int reverse(int x) {
        int temp = 0;
        bool flag = false;
        if(x<0){
            flag = true;
            x = abs(x);
        }
        int prev = temp;
        while(x>0){
            int rem = x%10;
            temp = temp*10 + rem;
            if ((temp - rem)/10 != prev){
                return 0;
            }
            prev = temp;
            x = x/10;
        }
        if(flag){
            return -1*temp;
        }
        else{
            return temp;
        }
    }
};