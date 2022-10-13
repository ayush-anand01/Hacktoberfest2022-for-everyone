#include <iostream>
using namespace std;
class node
{
    public:
    int data;
    node*next;
    node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};
node*takeInput()
{
    int data;
    cout<<"Enter the elements of the linked list"<<endl;
    cin>>data;
    node*head=NULL;
    node*tail=NULL;
    while(data!=-1)
    {
        node*newNode=new node(data);
        if(head==NULL && tail==NULL)
        {
            head=newNode;
            tail=newNode;
        }
        else
        {
            tail->next=newNode;
            tail=tail->next;
        }
        cin>>data;
    }
    return head;
}
void display(node*head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"\t";
        temp=temp->next;
    }
    cout<<endl;
}
node*midElement(node*head)
{
    if(head==NULL ||head->next==NULL)
    {
        return head;
    }
    node*slow=head;
    node*fast=head->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
node*mergeTwoLL(node*head1,node*head2)
{
    if(head1==NULL)
    {
        return head2;
    }
    if(head2==NULL)
    {
        return head1;
    }
    node*newHead=NULL;
    node*newTail=NULL;
    if(head1->data<head2->data)
    {
        newHead=head1;
        newTail=head1;
        head1=head1->next;
    }
    else
    {
        newHead=head2;
        newTail=head2;
        head2=head2->next;
    }
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->data<head2->data)
        {
            newTail->next=head1;
            newTail=newTail->next;
            head1=head1->next;
        }
        else
        {
            newTail->next=head2;
            head2=head2->next;
            newTail=newTail->next;
        }
    }
    if(head1!=NULL)
    {
        newTail->next=head1;
    }
    if(head2!=NULL)
    {
        newTail->next=head2;
    }
    return newHead;
}
node*mergeSort(node*head)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    node*mid=midElement(head);
    node*head1=head;
    node*head2=mid->next;
    mid->next=NULL;
    head1=mergeSort(head1);
    head2=mergeSort(head2);
    node*answer=mergeTwoLL(head1,head2);
    return answer;
}

int main()
{
    node*head=takeInput();
    display(head);
    head=mergeSort(head);
    cout<<"Sorted array : ";
    display(head);
    
    return 0;
}
