class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int len = strs.size();
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mp;
        //cout<<len;
        for(int i=0;i<len;i++){
            string tempStr = strs[i];
            sort(tempStr.begin(),tempStr.end());
            mp[tempStr].push_back(strs[i]);
        }
        unordered_map<string,vector<string>>:: iterator it;
        for(it = mp.begin(); it!=mp.end();it++){
            ans.push_back(it->second);
        }
        return ans;
    }
};