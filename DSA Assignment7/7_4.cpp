#include<iostream>
using namespace std;

class node{

public:
int data;
node* next;

node(int val)
{
    data=val;
    next=NULL;
}
};

void insertAtTail(node* &head,int val)
{
    node* n = new node(val); //a node is created which already points to null and has data val
    if(head==NULL)
    {
        head=n;
        return;
    }
    node* current = head;
    while(current->next!=NULL)
    {
        current=current->next;
    }
    current->next=n;
}

void display(node* head)
//we are taking the value of head as an address
{
    node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
cout<<"NULL"<<endl;
}

void insertAfter(node* &prev_node,int new_data)
{
    if(prev_node==NULL)
    {cout<<"The previous node cannot be a NULL";
    return;}

    node* new_node = new node(new_data);
    new_node->next=prev_node->next;
    prev_node->next = new_node;
}

node* reverse(node* &head)
{
    node* prevptr=NULL;
    node* currptr = head;
    node* nextptr;
    while(currptr!=NULL)
    {
        nextptr = currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
    }
    return prevptr;
}

int count_node(node* head)
//as no changes are being made to the linked list we pass by variable and not the address
{
    node* current = head;
    int count=1;
    while(current->next!=NULL)
    {
        current=current->next;
        count++;
    }
    return count;
}


node* middle(node* head)
{
    node* slow = head;
    node* fast = head;
    while(fast!=NULL&&fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow; //hence this returns the middle node of the linked list
}

void pattern(node* &head)
{
    node* curr = head;
    int count = count_node(curr);
    node* mid = middle(head);//hence we got the middle node and all we have to do is reverse it.
    node* last = reverse(mid);// hence the portion of the linked list starting from the node after the middle gets reversed
    //and in the head pointer of this reversed linked list is stored in last
    //but remember that the 'mid+1' node points to NULL
    
    if(curr==NULL||curr->next==NULL)
    {
        return;
    }

    //if the linked list has even number of terms
    if(count%2==0)
    {
        while(curr->next->next!=NULL)
            {
                insertAfter(curr,last->data);
                curr=curr->next->next;
                last=last->next;
            }
    }

    //if linked list has odd number of terms
    if(count%2!=0)
    {
        while(curr->next!=NULL)
            {
                insertAfter(curr,last->data);
                curr=curr->next->next;
                last=last->next; 
            }
    }
     //display(last);
     //display(curr);
}

int main()
{

    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    insertAtTail(head,7);
    //insertAtTail(head,8);

    display(head);

    pattern(head);
    display(head);
    
    return 0;
}