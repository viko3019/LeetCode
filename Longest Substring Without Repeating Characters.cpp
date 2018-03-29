/*
Approach 1 - O(N^3) consider all substring then check for duplicate char
Approach 2 - the basic idea is, keep a hashmap which stores the characters in string as keys and their positions as values, and 
  keep two pointers which define the max substring. move the right pointer to scan through the string , and meanwhile update the 
  hashmap. If the character is already in the hashmap, then move the left pointer to the right of the same character last found. 
  Note that the two pointers can only move forward.
  Time(O(N))
*/
class Solution {
public:
    
    int approach2(string s){
        map<char, int> charMap;
        int start = -1;
        int maxLen = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (charMap.count(s[i]) != 0) {
                start = max(start, charMap[s[i]]);
            }
            charMap[s[i]] = i;
            maxLen = max(maxLen, i-start);
        }
        
        return maxLen;
    }
    
    int lengthOfLongestSubstring(string s) {
        return approach2(s);
    }
};