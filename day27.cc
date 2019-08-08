//将一个字符串转换成一个整数的功能，但是string不符合数字要求时返回0要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0。

class Solution {
public:
    int StrToInt(string str) {
        if(str.size() == 0)
            return 0;
        
        int i = 0;
        int flag = 0;
        if(str[i] == ' ')
            i++;
        if(str[i] == '+')
        {
            flag = 1;
            i++;
        }
        else if(str[i] == '-')
        {
            flag = -1;
            i++;
        }
        
        int ret = 0;
        while(str[i] != '\0')
        {
            if(str[i] >= '0' && str[i] <= '9')
            {
                ret = ret * 10 + (str[i] - '0');
                i++;
            }
            else{
                ret = 0;
                break;
            }
        }
        if(flag == -1)
            ret = -ret;
        
        return ret;
        
    }
};
