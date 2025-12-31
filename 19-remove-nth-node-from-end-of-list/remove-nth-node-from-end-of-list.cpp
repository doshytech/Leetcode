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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int ct = 0;
        ListNode* dum = head;
        while(dum!=NULL){
            ct++;
            dum = dum->next;
        }
        int val = ct-n, pt = 0;
        ListNode* prev = new ListNode();
        ListNode* curr = head;
        ListNode* res = prev;
        // cout<<ct<<" "<<val<<endl;
        while(curr!=NULL){
            if(pt==val){
                curr = curr->next;
                prev->next = curr;
                prev = prev->next;
                if(curr!=NULL)curr = curr->next;
            }
            else{
                prev->next = curr;
                prev = prev->next;
                curr = curr->next;
            }
            pt++;
        }
        return res->next;
    }
};