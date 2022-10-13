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
void printReverse(node*head)
{
    if(head==NULL )
    {
        return ;
    }
    printReverse(head->next);
    cout<<head->data<<"\t";
}
int main()
{
    node*head=takeInput();
    display(head);
    cout<<"The reverse of the linked list is :";
    printReverse(head);
    
    
    return 0;
}
