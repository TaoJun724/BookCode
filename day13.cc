//地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
//

class Solution {
public:
    
    //设置一个二维数组，每个元素是该位置的标志。标志位true标识可以走。
    vector<vector<bool>> flag;
    
    int movingCount(int threshold, int rows, int cols)
    {
        //初始化所有元素都用false
        for(int i = 0;i < rows;i++)
        {
            vector<bool> vt;
            for(int j = 0;j < cols;j++)
            {
                vt.push_back(false);
            }
            flag.push_back(vt);
        }
        return MoveCount(threshold,rows,cols,0,0);
    }
    
    int MoveCount(int threshold,int rows,int cols,int i,int j)
    {
        if(i < 0 || i >= rows || j < 0 || j >= cols ||
            !LegalOrNot(threshold,i,j)||flag[i][j])
            return 0;
        
        flag[i][j] = true;
        return MoveCount(threshold,rows,cols,i - 1,j) +
            MoveCount(threshold,rows,cols,i + 1,j) +
            MoveCount(threshold,rows,cols,i ,j - 1) +
            MoveCount(threshold,rows,cols,i ,j + 1) + 1;
    }
    
    //判断该位置是否合法，是否可以访问
    bool LegalOrNot(int threshold,int row,int col)
    {
        int num = 0;
        while(row != 0)
        {
            num += row % 10;
            row /= 10;
        }
        while(col != 0)
        {
            num += col % 10;
            col /= 10;
        }
        if(num <= threshold)
            return true;
        return false;
    }
};

