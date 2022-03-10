//bubble ort using linked list
#include<iostream>
using namespace std;

class node{

public:
int data;
node* next;

node(int val)
{
    data = val;
    next = NULL;
}

};

void insertAtTail(node* &head, int val)
//we are taking value of head by address because we want to modify our linked list
{
    node* n = new node(val);
    
    //incase we are adding the first node to the linked list just use the below if statement
    if(head==NULL)
    {
        head=n;
        return;
    }

    node* temp = head;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    //when temp reaches null, insert the node at the tail
    temp->next=n;
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

void bubbleSort(node* &head)
{ //The bubble sort code was simply changed by using pointers instead of variables
    node* current = head;
    for(node* i = current;i->next->next!=NULL;i=i->next)
        { //i<n-1      ANALOGOUS TO THIS
            for(node* j=current;j->next!=NULL;j=j->next)
            { //j<n    ANALOGOUS TO THIS
                if(j->data>j->next->data)
                {
                    int temp;
                    temp=j->data;
                    j->data=j->next->data;
                    j->next->data=temp;
                }
            }
        }
        
}

 

int main()
{

    node* head = NULL;
    insertAtTail(head,34);
    insertAtTail(head,5);
    insertAtTail(head,12);
    insertAtTail(head,89);
    insertAtTail(head,0);
    insertAtTail(head,46);

    display(head);

    bubbleSort(head);

    display(head);

    return 0;
}