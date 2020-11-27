//
// Created by Harry Huang on 2020-11-26.
//

#ifndef LEETCODE_141_LINKEDLISTCYCLE_H
#define LEETCODE_141_LINKEDLISTCYCLE_H

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return false;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
            {
                return true;
            }
        }
        return false;
    }
    //TC:O(n)
    //SC:O(1)
};

#endif //LEETCODE_141_LINKEDLISTCYCLE_H
