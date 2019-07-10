//之字打印二叉树
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

//使用奇数偶数栈
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> ret;
        vector<int> tmp;
        
        if(pRoot == nullptr)
            return ret;
        
        stack<TreeNode*> odd_stack;
        stack<TreeNode*> even_stack;
        
        odd_stack.push(pRoot);
        while(!odd_stack.empty() || !even_stack.empty()){
            int top = 0;
            TreeNode* pNode;
            
            //打印奇数行，从左到右
            while(!odd_stack.empty())
            {
                pNode = odd_stack.top();
                top = pNode -> val;
                odd_stack.pop();
                
                tmp.push_back(top);
                //下一层是从右向左打印，所以左子树先入栈，右子树再入栈
                if(pNode -> left != nullptr)
                    even_stack.push(pNode -> left);
                if(pNode -> right != nullptr)
                    even_stack.push(pNode -> right);
            }
            
            if(tmp.size() != 0)
                ret.push_back(tmp);
            tmp.clear();
            
            //打印偶数行
            while(!even_stack.empty()){
                pNode = even_stack.top();
                top = pNode -> val;
                even_stack.pop();
                
                tmp.push_back(top);
                if(pNode ->right != nullptr)
                    odd_stack.push(pNode -> right);
                if(pNode -> left != nullptr)
                    odd_stack.push(pNode -> left);
            }
            if(tmp.size() != 0)
                ret.push_back(tmp);
            tmp.clear();
        }
        return ret;
            
    }
    
};

