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

    int pairSum(ListNode* head) {
        ListNode* s=head;
        vector<int>ll;
        while(s){
            ll.push_back(s->val);
            s=s->next;
        }
        int i=0;
        int j=ll.size()-1;
        int ans=0;
        while(i<j){
            ans=max(ans,ll[i]+ll[j]);
            i++,j--;
        }
        return ans;
        
    }
};