class Solution {
public:
    static bool comparator(pair<int,int>& a, pair<int,int>& b){
        return (a.second > b.second);
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>count;
        vector<int>ans;
        int n = nums.size();
        for(int i:nums){
            count[i]++;
        }
        vector<pair<int,int>> count_vector(count.begin(),count.end()); // Converting map to vector to sort based on comparator
        sort(count_vector.begin(),count_vector.end(),comparator);
        for(int i=0;i<k && i<count_vector.size();i++)
            ans.push_back(count_vector[i].first);

        return ans;
    }
};