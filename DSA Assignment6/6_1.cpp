#include<iostream>
using namespace std;

class Node{
  public:
  Node* next;
  int key;  
};

void push(Node** head_ref, int new_key)
{
    Node* new_node = new Node();
    new_node->key=new_key;
    new_node->next=*(head_ref);
    *head_ref = new_node;
}

void print(Node* head_ref)
{
    Node* current = head_ref;
    while(current!=NULL)
    {
        cout<<current->key<<" ";
        current=current->next;
    }
}

Node* copyList(Node* head_ref)
{
  // pointer to traverse the given linked list
    Node* current = head_ref; 

  // create a new linked list
Node* newList = NULL;  

    // tail pointer to point the new list's last node.
    Node* tail = NULL;      
 
    while (current != NULL)
    {
        // if the new list is empty
        // insert the first node
        if (newList == NULL)
        {
            newList = (Node*)malloc(sizeof(Node));
            newList->key = current->key;
            newList->next = NULL;
            tail = newList;
        }
        else {
            tail->next = (Node*)malloc(sizeof(Node));
            tail = tail->next;
            tail->key = current->key;
            tail->next = NULL;
        }
        current = current->next;
    }
 
    return newList;
}

string check_loop(Node* head_ref)
{
    //traverse till the last node till the time you reach the last node
    Node* current = head_ref; 
    while(current->next!=NULL)
    {
        current=current->next;
    }

    if(current->next==NULL)
    return "No loop present\n";

    else
    return "Loop present\n";
}

Node* reverse_ll(Node* head_ref)
//The idea is to update the 'next' part of one node at a time which is pointed by the head pointer
{
    Node* current = head_ref;
    Node* prev = NULL;
    Node* nex = NULL;

while(current!=NULL)
{
    nex = current->next;// address of the second node is stored
    current->next=prev; // address of the second node is made NULL
    prev=current;//Now the prev variable holds the address of the first node so as to not lose track of it
    current = nex;//now the 
    //if we want to update the 2nd node, we have to move our head pointer to the second node
}
   current = prev; // this way the head points to the last node of the list and the linked list gets reversed
    return current;
}

void check_palindrome(Node* head_ref)
{
    Node* start = head_ref;

    Node* end = reverse_ll(start);
}

int main()
{
    Node* head = NULL;
    push(&head,6);
    push(&head,7);
    push(&head,89);

    print(head);
    
    //checking if the string has loop
    cout<<endl<<check_loop(head);
    //reversing a linked list
    cout<<endl;
    Node* head1 = copyList(head);
    cout<<endl;
    print(head1);
    cout<<endl;
    head1 = reverse_ll(head);
    
    print(head1);
    cout<<endl;
    //print(head);
    //checking for a palindrome
    return 0;
}