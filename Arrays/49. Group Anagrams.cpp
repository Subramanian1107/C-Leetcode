class Solution {
public:
    string getKey(string s){
        vector<int>count(26,0);
        for(int i=0;i<s.size();i++)
            count[s[i]-'a']++;
        string key = "";
        for(int i=0;i<26;i++){
           // printf("%d\n",count[i]);
            key.append(to_string(count[i])+'$');
        }
           // key.append(to_string(count[i]));
        return key;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>mp;
        vector<vector<string>>res;
        for(int i=0;i<strs.size();i++){
            string key = getKey(strs[i]);
            printf("%s %s\n",strs[i].c_str(), key.c_str());
            mp[key].push_back(strs[i]);
        }
        for(auto it:mp){
            res.push_back(it.second);
        }
        return res;
    }
};
// Getting key for each string and matching that key to the same map element. map<key,vector<string>> 