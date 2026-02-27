#include<iostream>
using namespace std;
class ListNode
{
   public:
   int data;
   ListNode * next;

   ListNode(int data)
   {
      this->data=data;
      this->next=NULL;
   }
};
void insert(int val,ListNode *&tail)
{
   // ListNode * temp=tail;
   ListNode * temp1=new ListNode(val);
   if(tail==NULL)
   {
    tail->next=temp1;
   }
   tail->next=temp1;
   tail=temp1;
   ;
   
}

// here we are sorting the list.
void sort(ListNode *& head)
{
//   cout<<head->data;
   ListNode* temp=head;
   int zero=0;
   int one=0;
   int two=0;
   while(temp !=NULL)
   {
      //  cout<<"hii";
      if(temp->data==0)
      {
         zero++;
      }
      else if(temp->data==1)
      {
         one++;
      }
      else if(temp->data==2)
      {
         two++;
      }
      temp=temp->next;
   }





   temp=head;
   while(temp!=NULL)
   {
      if(zero != 0)
      {
         temp->data=0;
         // temp=temp->next;
         zero--;
      }
      else if(one != 0)
      {
        
        temp->data=1;
      //   temp=temp->next;
        one--;
      }
      else if(two != 0)
      {
         temp->data=2;
         // temp=temp->next;
         two--;
      }
      // cout<<"hi";
      temp=temp->next;
   }
}
void print(ListNode * head)
{
   ListNode * temp=head;

   while(temp != NULL)
   {
      cout<<temp->data;
      if(temp->next !=nullptr)
      {
         cout<<"->";
      }
      temp=temp->next;
   }
}

// this is the main section.
int main()
{
   int data=10;
   ListNode * head=new ListNode (2);
   ListNode * tail=head;
   insert(0,tail);
   insert(1,tail);
   insert(1,tail);
   insert(0,tail);
   print(head);
   cout<<endl;
   sort(head);
   print(head);

}
