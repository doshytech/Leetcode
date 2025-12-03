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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;

        ListNode *pA = headA;
        ListNode *pB = headB;

        // Traverse both lists, switching heads when reaching the end
        while (pA != pB) {
            pA = (pA) ? pA->next : headB;
            pB = (pB) ? pB->next : headA;
        }

        // Either intersection node or nullptr if no intersection
        return pA;
    }
};