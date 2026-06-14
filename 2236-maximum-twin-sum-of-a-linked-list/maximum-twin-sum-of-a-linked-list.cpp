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
        int s=head->val;
        vector<int>arr;
        ListNode * temp=head;
        while(temp!=NULL)
        {
            arr.push_back(temp->val);
            temp=temp->next;
        }
        int size=arr.size();
        size=size-1;
        int i=0;
        int sum=0;
        sum=arr[i]+arr[size];
        int sum1=sum;
        i=i++;
        size=size--;
        while(i<size)
        {
         int sum2=arr[i]+arr[size];
         size--;
         i++;
         sum1 = max(sum2,sum1);
        }
        // cout<<sum1;
    return sum1;
    }
};