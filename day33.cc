//所有和为S的连续正数序列

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> ret;
        if(sum < 3)
            return ret;
        
        vector<int> tmp;
        int begin = 1;
        int end = 2;
        int Sum = begin + end;
        while(begin <= sum / 2)
        {
            while(Sum > sum)
            {
                Sum -= begin;
                begin++;
            }
            if(Sum == sum && end - begin >= 1)
            {
                tmp.clear();
                for(int i = begin;i <= end;i++)
                    tmp.push_back(i);
                 ret.push_back(tmp);
            }
                       
               end++;
              Sum += end;
        }
        return ret;
    }
    
};

