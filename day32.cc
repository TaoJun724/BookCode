//把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。


class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.size() == 0) return 0;
        
        int length = rotateArray.size();
        for(int i = 0; i < length - 1;i++)
        {
            //因为是旋转数组，当rotateArray[i] > rotateArray[i + 1]说明rotateArray[i + 1]是最小的，否则是个递增数列输出第一个元素
            if(rotateArray[i] > rotateArray[i + 1])
                return rotateArray[i + 1];
        }
        return rotateArray[0];
    }
};
