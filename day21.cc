//输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        vector<int> leftSubTree;
        vector<int> rightSubTree;
        
        int root = 0;
        int flag = 0;
        bool ret = true;
        
        if(sequence.empty()) 
            return false;
        
        root = *(sequence.end() -  1);
        for(auto it = sequence.begin();it != sequence.end() - 1;it++)
        {
            if(*it < root && flag == 0)
                leftSubTree.push_back(*it);
            else if(*it > root)
            {
                flag = 1;
                rightSubTree.push_back(*it);
            }
            else 
            {
                rightSubTree.push_back(*it);
            }
        }
        
        for(auto it= rightSubTree.begin();it != rightSubTree.end();it++)
        {
            if(*it < root)
            {
                ret = false;
                break;
            }
        }
        
        if(ret == false)
            return false;
        
        if(!rightSubTree.empty()&&!leftSubTree.empty())
            ret = VerifySquenceOfBST(rightSubTree)&&VerifySquenceOfBST(leftSubTree);
        else if(!rightSubTree.empty() && leftSubTree.empty())
            ret = VerifySquenceOfBST(rightSubTree);
        else if(rightSubTree.empty()&&!leftSubTree.empty())
            ret = VerifySquenceOfBST(leftSubTree);
        else 
            ret = true;
        return ret;
        
    }
};

