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
        int count=0;
        ListNode * temp=head;
        if(head==NULL || head->next==NULL )
        {
           return NULL;
        }
       
        while(temp != NULL)
        {
            temp=temp->next;
            count++;
        }
        int mid=count/2+1;
        int s=1;
        ListNode * pre=NULL;
        ListNode * curr=head;
        while(s!=mid)
        {
            pre=curr;
            curr=curr->next;
            s++;
        }
        pre->next=curr->next;
        ListNode * temp2=curr;
        curr=curr->next;
        
       
        // cout<<mid;
        return head;
    }
};