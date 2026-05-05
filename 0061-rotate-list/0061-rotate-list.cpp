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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head||!head->next) return head;
        ListNode* temp=head;
        int n=0;
        while(temp){
            n++;
            temp=temp->next;
        }
        k=k%n;
        if(k==0) return head;

        ListNode* ptr=head;
        for(int i=1;i<n-k;i++) ptr=ptr->next;

        ListNode* newhead=ptr->next;
        ptr->next=NULL;
        ListNode* tptr=newhead;
        while(tptr->next!=NULL){
            tptr=tptr->next;
        }
        tptr->next=head;
        return newhead;
    }
};