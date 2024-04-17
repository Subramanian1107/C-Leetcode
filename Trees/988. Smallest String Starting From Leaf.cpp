//Method 1
class Solution {
public:
    void rootToLeaf(TreeNode* root,string s,string &ans){
        if(root == NULL)
            return;
        s+=char(root->val+97);
        if(root->left == NULL && root->right == NULL){
            string t = s;
            reverse(t.begin(),t.end());
            if(t < ans){
                ans = t;
            }
        }
        rootToLeaf(root->left,s,ans);
        rootToLeaf(root->right,s,ans);
    }
    string smallestFromLeaf(TreeNode* root) {
        string ans = "zzzzzzzzzzzzzz";
        string s = "";
        rootToLeaf(root,s,ans);
        return ans;
    }
};
// Updated Method
class Solution {
public:
    void rootToLeaf(TreeNode* root,string s,string &ans){
        if(root == NULL)
            return;
        s = char(root->val+97) + s;
        if(root->left == NULL && root->right == NULL){
            if(s < ans || ans.empty())
                ans = s;
        }
        rootToLeaf(root->left,s,ans);
        rootToLeaf(root->right,s,ans);
    }
    string smallestFromLeaf(TreeNode* root) {
        string ans = "";
        string s = "";
        rootToLeaf(root,s,ans);
        return ans;
    }
};