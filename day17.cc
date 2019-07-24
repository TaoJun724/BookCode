//输入一个链表，反转链表后，输出新链表的表头。
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
    ListNode* ReverseList(ListNode* pHead) {
            if(pHead == nullptr)
                return nullptr;
            ListNode* prev = nullptr;
            ListNode* next = nullptr;
            while(pHead)
            {
                next = pHead -> next;
                pHead -> next = prev;
                prev = pHead;
                pHead = next;
            }
            return prev;
    }
};

