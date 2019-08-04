//输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

class Solution {
public:
    
    //思路：找到奇数与偶素，为了保障它们的相对位置不变，找到一对，就将他么之间的数字移动
    void reOrderArray(vector<int> &array) {
      int index1 = 0;//奇数
      int index2 = 0;//偶数
      
      int i = 0;
      int k = 0;
        
      while(i < array.size() && k < array.size())
      {
          while(i < array.size())
          {
              if(array[i] % 2 == 0)//找到偶数
              {
                  index2 = array[i];
                  break;
              }
              i++;
          }
          k = i + 1;
          while(k < array.size())
          {
              if(array[k] % 2 != 0)//找到奇数
              {
                  index1 = array[k];
                  break;
              }
              k++;
          }
          if(k < array.size())
          {
              for(int j = k;j > i;j--)
              {
                  array[j] = array[j - 1];
              }
              array[i++] = index1;
          }
          else 
          {
              break;
          }
      }
    }
};

