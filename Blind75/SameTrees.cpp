class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL){
            return true;
        }
        if(p == NULL || q == NULL){
            return false;
        }
        return((p->val == q-> val)&&isSameTree(p-> left,q-> left)&&isSameTree(p->right, q-> right));
    }
};
//TC-> O(n) and SC-> O(h)