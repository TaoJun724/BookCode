//在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组,求出这个数组中的逆序对的总数P。

class Solution {
public:
    long GetCount( vector<int> &data, vector<int> &copy, long start, long end){
        if(start == end)  
            return 0 ;  
  
        long mid = start + (end - start) / 2;
        long lCount = GetCount(copy, data, start, mid); 
        long rCount = GetCount(copy, data, mid + 1, end);
        long crossCount = 0 ;     
        long left = mid, right = end, temp = end; 
        
        while(left >= start && right > mid) {   
            if (data[left] > data[right]) {   
                copy[temp--] = data[left--];
                crossCount += right - start - (mid-start);
            } else {
                copy[temp--] = data[right--];   
            }
        }
        while(left >= start) {
            copy[temp--] = data[left--];
        }
        while(right > mid) {
            copy[temp--] = data[right--];
        }        
        return (lCount + rCount + crossCount) % 1000000007; 
    }
    
    int InversePairs(vector<int> &data) {
        if(data. size () == 0 ) return 0 ;
        else if (data. size() == 1 ) return 1 ;
        else {
            vector<int> copy(data);
            return GetCount(data, copy, 0 , data.size()- 1);
        }
    }

};
