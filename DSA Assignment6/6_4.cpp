//Floyd's cycle detection algorithm is to be used to detect a loop in a linked list.

#include<iostream>
using namespace std;

class node{
public:

node* next;
int data;

//constructor
node(int val)
{
    data=val;
    next=NULL;
}

};

void insertAtHead(node* &head, int val)
{
    node* n = new node(val);
    n->next = head; //this is the node that is to be inserted at the beginning. 
    //Currently head is pointing to the "2nd element". So this step points n to the 2nd element as n is supposed to be the 1st element
    head=n; //using this we change head to point to n. and n becomes the first element.
}

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

bool detectCycle(node* &head)
{
    node* slow = head;
    node* fast = head;
    
    while(fast!=NULL&&fast->next!=NULL)
    {
        slow=slow->next;// moves 1 step at a time
        fast = fast->next->next;//moves 2 steps at a time
    
        //in case cycle is present
        if(slow==fast)
        {
            return true;
        }


    }
    //in case cycle is not present in the loop

    return false;
}

void makeCycle(node* &head, int pos)
{
    //pos tells the position from which we want the loop to start
    node* temp = head;
    node* startNode;

    int count=1;
    while(temp->next!=NULL)
    {
        if(count==pos)
        {
            startNode = temp;//assigns that position to new pointer from where the loop is to start
        }
        
        temp = temp->next;
        count++;
    }
    
    //at the end of the loop, temp points to the last node of the linked list
    temp->next=startNode;
    //this connects the end to this loop

}

int main()
{
 
    node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtHead(head,4);
    display(head);
    makeCycle(head,3);
    //display(head);

    detectCycle(head)?cout<<"Cycle is present":cout<<"Cycle is absent";

 
    return 0;
}