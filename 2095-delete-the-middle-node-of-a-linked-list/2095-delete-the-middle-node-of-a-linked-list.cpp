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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head->next) return {};
        ListNode* temp=head;
        int n=0;
        while(temp){n++; temp=temp->next;}
        int mid=n/2;
        temp=head;
        ListNode* prev=NULL;
        ListNode* next=NULL;
        for(int i=1;i<=mid;i++){
            prev=temp;
            temp=temp->next;
            next=temp->next;
        }
        prev->next=next;
        return head;
    }
};