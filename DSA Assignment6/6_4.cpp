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

int main()
{
    return 0;
}