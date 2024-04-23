class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n-1;
        int ans = -1e9;
        while(left<right){
            int containerHeight = min(height[left],height[right]);
            int containerWidth = right-left;
            if(containerHeight * containerWidth > ans)
                ans = containerHeight * containerWidth;
            if(height[left] < height[right])
                left++;
            else if(height[left] > height[right])
                right--;
            else
            {
                left++;
                right--;
            }
        }
        return ans;
    }
};