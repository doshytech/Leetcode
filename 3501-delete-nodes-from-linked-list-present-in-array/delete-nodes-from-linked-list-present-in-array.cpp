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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(),nums.end());
        ListNode* curr = head;
        ListNode* prev = new ListNode(0);
        ListNode* ans = new ListNode(0);
        bool tk = 0;
        while(curr!=NULL){
            if(st.find(curr->val)==st.end()){
                if(!tk){
                    ans->next = prev, tk = 1;
                }
                prev->next = curr;
                prev = prev->next;
            }
            curr = curr->next;
        }
        prev->next=NULL;
        return ans->next->next;
    }
};