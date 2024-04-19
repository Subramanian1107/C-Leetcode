Method 1
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>maxLeft(n,0);
        vector<int>maxRight(n,0);
        maxRight[n-1] = height[n-1];
        maxLeft[0] = height[0];
        int ans = 0;
        for(int i=1;i<n;i++)
            maxLeft[i] = max(maxLeft[i-1],height[i]);
        for(int i=n-2;i>=0;i--)
            maxRight[i] = max(maxRight[i+1],height[i]);
    
        for(int i=1;i<n-1;i++){
            // cout<<maxLeft[i]<<" "<<maxRight[i]<<endl;
            int trap = min(maxLeft[i],maxRight[i]) - height[i];
            ans+= trap;
            // cout<<ans<<endl;
        }
        return ans;

    }
};
Method 2
class Solution {
public:
    int trap(vector<int>& height) 
    {
        int n = height.size();
        int maxLeft = 0;
        int maxRight = n-1;
        int left = 0;
        int right = n-1;
        int ans = 0;
        while(left<right){
            if(height[left]<height[right]){
                if(height[left]>= height[maxLeft])
                    maxLeft = left;
                left++;
                if(height[maxLeft] > height[left])
                    ans+= height[maxLeft] - height[left];
            }
            else{
                if(height[right]>= height[maxRight])
                    maxRight = right;
                right--;
                if(height[maxRight] > height[right])
                    ans+= height[maxRight] - height[right];
            }
            // cout<<maxLeft<<" "<<maxRight<<" "<<left<<" "<<right<<endl;
        }
        return ans;
    }
};
class Solution {
public:
    int trap(vector<int>& height) {
        int n= height.size();
        vector<int> left(n);
        vector<int> right(n);
        vector<int> trap(n);
        int max_left=INT_MIN, max_right=INT_MIN;
        for(int i=0; i<n; i++){
            left[i]=max(height[i],max_left);
            max_left=left[i];
        }
        for(int i=n-1; i>-1; i--){
            right[i]=max(height[i],max_right);
            max_right=right[i];
        }
        int sum=0;
        for(int i=0; i<n; i++){
            // cout<<left[i]<<" "<<right[i]<<endl;
            trap[i]= min(left[i],right[i])-height[i];
            cout<<trap[i]<<endl;
            sum+=trap[i];
        }
        
        return sum;
        
    }
};