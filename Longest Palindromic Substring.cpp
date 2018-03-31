/*
  Approach 1 - O(N^3) for all possible subtring check that is a palindrom or not
  
  Approach 2 - O(N^2) expand arround center(take care of even and odd length palindrom case)
  In this approch we choose center as i or i,i+1 in case of even length palindrom, and we expand the string in both direction.

*/

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        string ans = "";
        if(len == 0){
            return ans;
        }
        string ans1 = s.substr(0,1);
        int cnt1 = 1;
        //case 1 considering odd length string
        for(int i=1;i<len;i++){
            int j = i-1;
            int k = i+1;
            while(j>=0 && k<len && s[j] == s[k]){
                if(k-j+1 > cnt1){
                    ans1 = s.substr(j,k-j+1);
                    cnt1 = k-j+1;
                    //cout<<ans1<<endl;
                }
                j--;k++;
            }
        }
        
        //case 2 considering even length palindrom
        string ans2 = "";
        int cnt2 = 0;
        for(int i=0;i<len-1;i++){
            if(s[i] == s[i+1]){
                int j = i-1;
                int k = i+2;
                if(ans2.length() == 0) {
                    ans2 = s.substr(i,2);
                }
                while(j>=0 && k<len && s[j] == s[k]){
                    if(k-j+1>cnt2){
                        ans2 = s.substr(j,k-j+1);
                        cnt2 = k-j+1;
                       // cout<<ans2<<" ";
                    }
                    j--;k++;
                }
            }
        }
        if(ans1.length()>ans2.length()){
            return ans1;
        }
        else{
            return ans2;
        }
        
        //return ans1;
    }
};