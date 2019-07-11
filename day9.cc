//最长子序列的和


class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int sum = 0;
        int max = array[0];
        int len = array.size();
        
        for(int i = 0;i < len;i++){
            sum += array[i];
            if(max < sum)
                max = sum;
            
            if(sum < 0)
                sum = 0;
        }
        return max;
    }
};/最长子序列的和
//



