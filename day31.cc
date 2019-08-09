//栈的合法性

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        int inlen = pushV.size();
        int outlen = popV.size();
        //如果长度不同则不用判断,错误
        if(inlen != outlen)
            return false;
        
        stack<int> s;
        
        int in = 0,out = 0;
        for(in = 0;in < inlen;in++)
        {
            s.push(pushV[in]);
            while(!s.empty() && s.top() == popV[out])
            {
                s.pop();
                out++;
            }
        }
        return s.empty();
        
    }
};

