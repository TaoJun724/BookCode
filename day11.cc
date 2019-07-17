//【题目】在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
//【思路】类似于杨氏矩阵，从右上角判断，如果右上角的数字大于所找数字，说明在本行，将其列数减少；反之将行数增加，依次循环。
//
//


class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int row = array.size();
        int col = array[0].size();
        
        int i = 0;
        int j = col - 1;
        while(i < row && j >= 0)
        {
            if(array[i][j] > target)
                j--;                             
            else if(array[i][j] < target)
                i++;                
            else
                return true;
        }      
        return false;
    }
};
