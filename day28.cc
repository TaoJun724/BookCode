//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
       int length = numbers.size();
        
       int i = 0, j = 0;
       int count = 0;
       for(i = 0;i < length;i++)
       {
           count = 0;
           for(j = 0;j < length;j++)
           {
               if(numbers[i] == numbers[j])
                   count++;
           }
           if(count > length / 2)
              return  numbers[i];
       }
        return 0;
    }
};

