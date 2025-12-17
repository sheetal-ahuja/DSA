// TC: O(n*n)
class Solution {
public:
    int height(TreeNode* root){
        if(root == NULL) return 0;
        return max(height(root-> left), height(root-> right))+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int leftdia = diameterOfBinaryTree(root-> left);
        int rightdia = diameterOfBinaryTree(root-> right);
        int currdia = height(root-> left) + height(root-> right);

        return max(leftdia, max(rightdia, currdia));
    }
};

// Tc: O(n)
