//输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
//输入struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> v;
        ListNode* p = head;
        while(p != nullptr)
        {
            v.push_back(p -> val);
            p = p -> next;
        }
        reverse(v.begin(),v.end());
       return v;
    }
};

做法二：利用栈。
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
     vector<int> v;
     if(head == NULL)
         return v;
      stack<ListNode*> st;
      ListNode* node = head;
      while(node != NULL)
      {
          st.push(node);
          node = node -> next;
      }
      while(!st.empty())
      {
          node = st.top();
          v.push_back(node->val);
          st.pop();
      }
        return v;
    }
};

//
//



