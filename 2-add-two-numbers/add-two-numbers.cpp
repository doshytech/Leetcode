/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* list1, ListNode* list2) {
        int carr = 0;
        ListNode* dum = new ListNode();
        ListNode* res = dum;
        while(list1!=NULL&&list2!=NULL){
            int val = list1->val+list2->val+carr;
            dum->val = val%10;
            carr = val/10; 
            if(carr||list1->next||list2->next)dum->next = new ListNode();
            dum = dum->next;
            list1 = list1->next;
            list2 = list2->next;
        }
        while(list1!=NULL){
            int val = list1->val+carr;
            dum->val = val%10;
            carr = val/10;
            // dum->next = new ListNode();
            if(carr||list1->next)dum->next = new ListNode();
            dum = dum->next;
            list1 = list1->next;
        }
        while(list2!=NULL){
            int val = list2->val+carr;
            dum->val = val%10;
            carr = val/10;
            if(carr||list2->next)dum->next = new ListNode();
            dum = dum->next;
            list2 = list2->next;
        }
        if(carr)dum->val+=carr;
        // else dum = NULL;
        return res;
    }
};