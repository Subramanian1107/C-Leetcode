class Solution {
public:
    int getPrefixProduct(int i,vector<int>& nums){
        int prefixProduct = 1;
        for(int j=0;j<i;j++)
            prefixProduct *= nums[j];
        return prefixProduct;
    }
    int getSuffixProduct(int i,vector<int>& nums){
        int suffixProduct = 1;
        for(int j=i+1;j<nums.size();j++)
            suffixProduct *= nums[j];
        return suffixProduct;
    }
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        vector<int>prefixProduct(n);
        vector<int>suffixProduct(n);
        prefixProduct[0] = 1;
        suffixProduct[n-1] = 1;

        for(int i=1;i<n;i++){
            prefixProduct[i] = nums[i-1] * prefixProduct[i-1];
            suffixProduct[n-i-1] = nums[n-i] * suffixProduct[n-i];
        }
            
        for(int i=0;i<nums.size();i++)
            ans[i] = prefixProduct[i]*suffixProduct[i];

        return ans;
    }
};