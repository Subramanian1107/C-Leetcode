class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>deadend{deadends.begin(),deadends.end()};
        if(deadend.count("0000"))
            return -1;
        if(target == "0000")
            return 0;
        int ans = 0;
        queue<string>q;
        q.push("0000");
        while(!q.empty()){
            ans++;
            for(int sz = q.size();sz>0;sz--){
                string word = q.front();
                // cout<<word<<endl;
                q.pop();
                    for(int i=0;i<4;i++){
                    char c = word[i];
                    word[i] = int(word[i]+1)%10;
                    if(word == target)
                        return ans;
                    if(!deadend.count(word)){
                        q.push(word);
                        deadend.insert(word);
                    }
                    word[i] = c;
                    word[i] = int(word[i]-1)%10;
                    if(word == target)
                        return ans;
                    if(!deadend.count(word)){
                        q.push(word);
                        deadend.insert(word);
                    }
                    word[i] = c;
                }
            }

        }
        return -1;


    }
};