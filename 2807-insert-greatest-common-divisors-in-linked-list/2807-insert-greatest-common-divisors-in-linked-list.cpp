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
    int gcd(int a, int b) {
        while(b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head->next) return head;
        ListNode* t=head;
        ListNode* prev=NULL;
        while(t->next && t){
            prev=t;
            t=t->next;
            int val=gcd(prev->val,t->val);
            prev->next=new ListNode(val);
            prev=prev->next;
            prev->next=t;
        }
        return head;
    }
};