class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        int maxCount = 0;
        for(auto it:st){
          //  cout<<it<<endl;
            if(st.find(it+1) == st.end()){
                int count = 1;
                while(st.find(it-1) != st.end()){
                    count++;
                    it = it-1;
                }
                maxCount = max(count,maxCount);
            }
        }
        return maxCount;

    }
};