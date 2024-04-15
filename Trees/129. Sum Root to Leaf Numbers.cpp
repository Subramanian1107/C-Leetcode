class Solution {
public:
    void findPathSum(TreeNode* root,int* sum,int num){
        if(root == NULL)
            return;
        num = num * 10 + root->val;
        if(root->left == NULL && root->right == NULL){
            (*sum)+=num;
            return;
        }
        if(root->left)
            findPathSum(root->left,sum,num);
        if(root->right)
            findPathSum(root->right,sum,num);
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        findPathSum(root,&sum,0);
        return sum;
    }
};