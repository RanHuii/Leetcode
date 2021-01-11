struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return;
       
        ListNode* current = head;
        ListNode* mid = findMiddle(current);
        ListNode* temp = mid->next;
        mid->next = nullptr;
        
        ListNode* right = reverseList(temp);
        
        mergeList(current, right);
        return;
    }
    
    ListNode* findMiddle(ListNode* head)
    {
        // find the left middle point
        ListNode* slow = head, *fast = head;
        while(fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* track;
        
        while(curr != nullptr)
        {
            track = curr->next;
            curr->next = prev;
            prev = curr;
            curr = track;
        }
        
        return prev;
    }
    
    void mergeList(ListNode* l1, ListNode* l2)
    {
        while(l1 && l2)
        {
            ListNode* temp = l1->next;
            ListNode* temp1 = l2->next;
            
            l1->next = l2;
            l1 = temp;
            
            l2->next = l1;
            l2 = temp1;
        }
        return;
    }
    
    //TC:O(n)
    //SC:O(1)
};