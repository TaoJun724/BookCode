//输入一棵二叉树，判断该二叉树是否是平衡树

class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot == nullptr)
            return true;
        
        int left = Deep(pRoot -> left);
        int right = Deep(pRoot -> right);
        int diff = left - right;
        if(diff > 1||diff < -1)
            return false;
        return IsBalanced_Solution(pRoot -> left)&&IsBalanced_Solution(pRoot -> right);
    }
    
    int Deep(TreeNode* pRoot)
    {
        if(pRoot == nullptr)
            return 0;
        int left = Deep(pRoot -> left);
        int right = Deep(pRoot -> right);
        return (left>right)?left+1:right+1;
    }
};
