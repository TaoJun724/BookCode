//删除链表中重复的节点

/*struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead == nullptr) return nullptr;
        ListNode* prev = nullptr;
        ListNode* cur = pHead;
        
        while(cur != nullptr)
        {
            if(cur -> next != nullptr && cur -> val == cur -> next -> val)
            {
                int value = cur -> val;
                while(cur -> next != nullptr && cur -> next ->val ==value)
                {
                    cur = cur -> next;
                }
                if(prev == nullptr)
                {
                    pHead = cur-> next;
                }else 
                {
                    prev -> next = cur -> next;
                }
            }
            else 
            {
                prev = cur;
            }
            
            cur = cur -> next;
        }
        return pHead;
      
    }
};
