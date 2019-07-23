//输入一个链表，输出该链表中倒数第k个结点。
//
//
//


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        int count = 0;
        ListNode *temp = pListHead;
        
        while(temp != NULL)
        {
            ++count;
            temp = temp -> next;
        }
        
        count -= k;
        temp = pListHead;
        if(count >= 0)
        {
            while(count--)
            {
                temp = temp -> next;
            }
            return temp;
        }
        else 
            return NULL;
    }
};

