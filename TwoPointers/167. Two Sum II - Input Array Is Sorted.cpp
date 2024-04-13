class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size()-1;
        while(left < right){
            int victim = target - numbers[left];
            if(victim == numbers[right]){
                return {left+1,right+1};
            }
            else if(victim > numbers[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return {-1,-1};
    }
};