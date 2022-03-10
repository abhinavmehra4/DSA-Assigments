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

int addition(int x, int y)
{
    int z = x+y;

    if(z/10==0)
    {
        return z;
    }
    if(z/10!=0)
    {
        
    }
}

Node* add(Node* head1, Node* head2)
{
    Node* x = head1;
    Node* y = head2;

    
    Node* head3 = NULL;

    while(head1!=NULL)
    {
        push(&head3,(x->key+y->key));
        x=x->next;
        y=y->next;
    }
    return head3;
}
int main()
{
    Node* head1 = NULL;
    push(&head1,6);
    push(&head1,5);
    cout<<endl;
    print(head1);

    Node* head2 = NULL;
    push(&head2,6);
    push(&head2,6);
    cout<<endl;
    print(head2);

    Node* head3 = NULL;

    head3 = add(head1,head2);

    print(head3);

    return 0;
}