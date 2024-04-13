class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int>count;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(count.find(nums[i]) != count.end())
                return true;
            count.insert({nums[i],1});
        }
        return false;
    }
};