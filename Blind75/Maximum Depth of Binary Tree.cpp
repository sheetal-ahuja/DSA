class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int dr = maxDepth(root-> right);
        int dl = maxDepth(root-> left);
        return(max(dr, dl)+1);
    }
};