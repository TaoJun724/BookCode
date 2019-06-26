//循环左移，现在有个简单的任务，就是用字符串模拟这个指令的运算结果。对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！



class Solution {
public:
    string LeftRotateString(string str, int n) {
        if(str == "")
            return str;
        
        int len = str.length();
        int flag = n % len;
        if(flag == 0)
            return str;
        
        string str1 = str.substr(0,flag);
        string str2 = str.substr(flag,len);
        
        str2.append(str1);
        return str2;
    }
};
