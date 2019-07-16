//题目描述
//请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。

class Solution
{
public:
    //Insert one char from stringstream
    void Insert(char ch)
    {
        str = str + ch;//逐个插入字符
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
    //  if (str == "") return NULL;
        int flag = 0;
        int label = -1;
        for (int i = 0;i < str.size();i++)
        {
            flag = 0;//flag==0,表示没有重复元素
            for (int j = 0;j < str.size();j++)
            {
                if (i != j&&str[i] == str[j])//有重复元素，则跳出循环
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)//判断有无重复元素,0表示无重复元素
            {
                label = i;
                break;
            }
        }
        if (label == -1)return '#';
        return str[label];
    }
    void print()
    {
        cout << "str:" << str << endl;
    }
private:
    string str;
};
