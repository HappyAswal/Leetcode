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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head->next || !head->next->next) return {-1,-1};
        vector<int>crit;
        ListNode* temp=head;
        int n=1;
        int x1=temp->val;
        temp=temp->next;
        while(temp && temp->next){
            n++;
            int x2=temp->val;
            int x3=temp->next->val;
            if(x2>x1 && x2>x3) crit.push_back(n);
            if(x2<x1 && x2<x3) crit.push_back(n);
            x1=x2;
            temp=temp->next;
        }
        int m=crit.size();
        if(m<2) return {-1,-1};
        int minima=INT_MAX;
        for(int i=1;i<m;i++){
            minima=min(minima,crit[i]-crit[i-1]);
        }
        int maxima=crit[m-1]-crit[0];
        return {minima,maxima};
    }
};