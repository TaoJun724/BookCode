//输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。

class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> ret;
        int len = str.length();
        
        if(len == 0)
            return ret;
        
        sort(str.begin(),str.end());
        Permutation(ret,str,0,len);
        return ret;
    }
    
    void Permutation(vector<string>& ret,string str,int index,int len)
    {
        if(index == len)
        {
            ret.push_back(str);
            return;
        }
        
        for(int i = index;i < len;++i){
            if(i != index && str[i] == str[index])
                continue;
            swap(str[i],str[index]);
            Permutation(ret,str,index + 1,len);
        }
    }
};

