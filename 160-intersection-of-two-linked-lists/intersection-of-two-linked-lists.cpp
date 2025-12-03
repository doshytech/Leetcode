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
        vector<ListNode*> a, b;
        ListNode* curr = headA;
        while(curr!=NULL){
            a.push_back(curr);
            curr = curr->next;
        }
        curr = headB;
        while(curr!=NULL){
            b.push_back(curr);
            curr = curr->next;
        }
        reverse(a.begin(),a.end()), reverse(b.begin(),b.end());
        ListNode* val = NULL;
        for(int i=0;i<min(a.size(),b.size());i++){
            if(a[i]==b[i])val = a[i];
        }
        return val;
    }
};