//给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针

/*struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode==NULL)
             return NULL;
         TreeLinkNode* next=NULL;

         //1.判断该节点的右节点是否为空,若不为空,则下一个节点为该节点一直遍历下去的最左节点

        if(pNode->right!=NULL)
        {
            TreeLinkNode*pRight=pNode->right;
            while(pRight->left!=NULL)
                pRight=pRight->left;
            return pRight;
        }

        //2.该节点的右节点为空，则分两种情况

        else if(pNode->next!=NULL)
        {

             //2.1若该节点为父节点的左子节点，那么下一个节点就是其父节点

            if(pNode->next->left==pNode)
                return pNode->next;

            //2.2 若该节点为父节点的右子节点，那么一直往父节点上面走，直到父节点为空，或者该节点是父节点的左节点(非右)

            else
            {
                TreeLinkNode*current=pNode;
                TreeLinkNode*parent=pNode->next;
                while(parent!=NULL&&current==parent->right)
                {
                    current=parent;
                    parent=parent->next;
                }
                return parent;
            }
        }
        return next;
    }
};

