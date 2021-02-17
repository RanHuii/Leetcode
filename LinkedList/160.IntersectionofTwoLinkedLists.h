struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
  };
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int a_size = find_size(headA);
        int b_size = find_size(headB);
        
        if(a_size < b_size)
        {
            int diff = b_size - a_size;
            for(int i = 0; i < diff; i++)
            {
                headB = headB->next;
            }
        }
        else
        {
            int diff = a_size - b_size;
            for(int i = 0; i < diff; i++)
            {
                headA = headA->next;
            }
        }
        while(headA && headB)
        {
            if(headA == headB)
            {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }
    int find_size(ListNode *head)
    {
        int counter = 0;
        while(head)
        {
            counter++;
            head = head->next;
        }
        
        return counter;
    }
    //TC:O(n) n = the length of the longer linkedlist.
    //SC:O(1)
};