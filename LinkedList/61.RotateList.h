
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0)
            return head;
        ListNode* end = head;
        ListNode* cur = head;
        ListNode* slow = head;
        // k can be huge, so calculate size and reduce k
        int size = 1;
        while(end ->next != nullptr)
        {
            end = end->next;
            size++;
        }
        
        if(k  % size == 0)
            return head;
        
        int modulated_k = k % size;
        int jump = size - modulated_k - 1;
        // find one position before the rotation
        for(int i = 0; i < jump; i++)
        {
            cur = cur->next;
        }
    
       
        ListNode* track = cur->next;
        cur->next = nullptr;
        end->next = head;
        
        return track;
        
        
    }
    //method 1: TC:max(O(k), O(n)) k is the rotation and n is the number of nodes. K can be huge
    //method 2: TC:O(N) N = number of nodes
    //SC:O(1)
};