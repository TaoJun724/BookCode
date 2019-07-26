//请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

class Solution {
public:
	void replaceSpace(char *str,int length) {
        int i = length - 1;
        int j = 0;
        while(i >= 0)
        {
            if(str[i] == ' ')
            {
                for(j = length; j >= i;j--)
                {
                    str[j + 2] = str[j];
                }
                str[i] = '%';
                str[i + 1] = '2';
                str[i + 2] = '0';
                length += 2;
            }
            i--;           
        }
	}
};
