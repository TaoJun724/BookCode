//输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int len = array.size();
        int i = 0;
        int j = 0;
        
        vector<int> ret;
        for(i = 0,j = len - 1;i < len && j > i;)
        {
            if(array[i] + array[j] == sum)
            {
                ret.push_back(array[i]);
                ret.push_back(array[j]);
                return ret;
            }
            else if(array[i] + array[j] > sum)
                j--;
            else 
                i++;
        }
        return ret;       
    }
};

