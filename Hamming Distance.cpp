class Solution {
public:
    int hammingDistance(int x, int y) {
        int xr = x^y;
        int m=1;
        int ans = 0;
        for(int i=0;i<31;i++){
            if(xr&m){
                ans++;
            }
            m=m*2;
        }
        return ans;
    }
};