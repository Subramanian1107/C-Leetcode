class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>ans;
        map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]=i;
        }

        for(int i=0;i<n;i++){
            int rem = target - nums[i];
            if(mpp.find(rem)!=mpp.end() && mpp[rem]!=i){
                ans.push_back(i);
                ans.push_back(mpp[rem]);
                break;
            }
        }
        return ans;
        
    }
};

