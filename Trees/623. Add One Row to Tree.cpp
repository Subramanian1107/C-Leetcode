class Solution {
public:
    void levelOrderTraversal(TreeNode* root,int val,int depth){
        if(root == NULL)
            return;
        if(depth == 2)
        {
            root->left = new TreeNode(val,root->left,NULL);
            root->right = new TreeNode(val,NULL,root->right);
            return;
        }
        levelOrderTraversal(root->left,val,depth-1);
        levelOrderTraversal(root->right,val,depth-1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1)
            return new TreeNode(val,root,NULL);
        levelOrderTraversal(root,val,depth);
        return root;
    }
};