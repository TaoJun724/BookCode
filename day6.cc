//对称的二叉数
//



struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        if (pRoot == NULL)//空树是对称二叉树，返回true
            return true;
        return check(pRoot->left,pRoot->right);//不为空树进入递归
    }
    
    bool check(TreeNode* left,TreeNode* right)
    {
        if (left == NULL && right == NULL)
            return true;
        if (left == NULL || right == NULL)
            return false;
        if ((left->val) == (right->val))
        {
            return check(left->left,right->right) && check(left->right,right->left);
        }
        return false;
    }

    

};

