//2019.6.27
//n皇后
class Solution {
public:
    bool isvalid(vector<string> &temp, int i, int j){//判断棋盘是否有效
        //for (int k = 0; k<temp[i].size(); ++k){//判断行。不用判断行了，每行放一个之后就会递归到下一行了
        //	if (temp[i][k] == 'Q') return false;
        //}
        for (int k = 0; k < i; ++k){//判断列
            if (temp[k][j] == 'Q') return false;
        }
        for (int p = i - 1, q = j - 1; p>=0 && q>=0; --p, --q){//判断左上对角线
            if (temp[p][q] == 'Q') return false;
        }
        for (int p = i - 1, q = j + 1; p >= 0 && q<temp.size(); --p, ++q){//判断右上对角线
            if (temp[p][q] == 'Q') return false;
        }
        return true;
    }
 
 
    void dfs(vector<vector<string> > &re, vector<string> &temp, int i, int n){
        if (i == n) {
            re.push_back(temp);
            return;
        }
        for (int j = 0; j<n; ++j){
            if (isvalid(temp, i, j)) {
                temp[i][j] = 'Q';//递归前修改
                dfs(re, temp, i + 1, n);
            }
            temp[i][j]='.';//递归后恢复
        }
        return;
    }
 
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> re;
        string aa;
        for (int i = 0; i < n; ++i)
            aa += '.';
        vector<string>temp(n,aa);
        dfs(re, temp, 0, n);
        return re;
    }
};
