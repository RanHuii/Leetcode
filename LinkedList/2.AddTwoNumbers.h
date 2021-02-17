
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carrier = 0;
        ListNode* head = new ListNode();
        ListNode* result = head;
        while(l1 || l2 || carrier)
        {
            int sum = 0;
            sum = carrier + (l1? l1->val:0) + (l2? l2->val:0);
            
            if(sum >= 10)
            {
                carrier = 1;
                sum -= 10;
            }
            else
            {
                carrier = 0;
            }
            head -> next = new ListNode(sum);
            head = head->next;
            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
            
        }
       
        
        return result->next;
        
        // TC:Max(N,M) N M is the length of the lists
        // SC:Max(N, M) N M is the length of the lists
    }
};