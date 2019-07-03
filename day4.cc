//ceng ci bianli

/*struct TreeNode {
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
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int>> ret;
            if(pRoot == nullptr)
                return ret;
            
            queue<TreeNode*> q;
            q.push(pRoot);
            while(!q.empty()){
                int start = 0,end = q.size();
                vector<int> temp;
                while(start < end){
                    TreeNode* node = q.front();
                    q.pop();
                    temp.push_back(node -> val);
                    if(node -> left != nullptr)
                        q.push(node -> left);
                    if(node -> right != nullptr)
                        q.push(node -> right);
                    start++;                     
                }
                ret.push_back(temp);
            }
            return ret;
        }
    
};

