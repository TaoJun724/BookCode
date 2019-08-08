//在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）


class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        int length = str.size();
        if(length == 0)
            return -1;
        
        int tableSize = 256;
        int hashTable[tableSize];
        for(int i = 0; i < tableSize; ++i)
             hashTable[i] = 0;
        
        for(int i = 0; i < length; i++){
            hashTable[str[i]]++;
        }
            
        for(int i = 0; i < length; i++){
            if(hashTable[str[i]] == 1)
                return i;
        }

        return -1;        
    }
};

