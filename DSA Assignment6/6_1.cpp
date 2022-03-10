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
    node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
cout<<"NULL"<<endl;
}

node* reverse_pointer(node* &head)

{
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;

    while(currptr!=NULL)
    {
        nextptr=currptr->next;\
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
    }
    return prevptr;//as we return the head but this head is the head of the reversed linked list
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

bool check_palindrome(node* head)
{
    if(head==NULL)
    {return true;}

    node* mid = middle(head);//hence we got the middle node and all we have to do is reverse it.
    node* last = reverse_pointer(mid->next);// hence the portion of the linked list starting from the node after the middle gets reversed
    //and in the head pointer of this reversed linked list is stored in last
    //but remember that the 'mid+1' node points to NULL
    node* curr = head;

    while(last!=NULL)
    {
        if(last->data!=curr->data)
        {
            return false;
        }
        last=last->next;
        curr=curr->next;
    }
    return true;
}

int main()
{
    node* head = NULL;
    insertAtTail(head,4);
    insertAtTail(head,2);
    insertAtTail(head,2);
    insertAtTail(head,4);
    display(head);

    cout<<check_palindrome(head)<<endl;
    
    check_palindrome(head)?cout<<"It is a palindrome"<<endl:cout<<"It is not a pallindrome"<<endl;
    
    
    return 0;
}