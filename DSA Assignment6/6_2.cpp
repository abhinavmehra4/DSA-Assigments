
#include <bits/stdc++.h>
using namespace std;
 
/* Linked list node */
class node {
public:
    int data;
    node* next;
};
 
/* Function to create a
new node with given data */
node* newNode(int data)
{
    node* new_node = new node();
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
 
/* Function to insert a node  */
void insert(node** head_ref, int new_data)
{
    /* allocate node */
    node* new_node = newNode(new_data);
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}
 
/* Adds contents of two linked lists and
return the head node of resultant list */
node* addTwoLists(node* f, node* s)
{
 
    // res is head node of the resultant list
    node* res = NULL;
    node *temp, *prev = NULL;
    int carry = 0, sum;
 
    // while both lists exist
    while (f != NULL
        || s != NULL) {
        // Calculate value of next
        // digit in resultant list.

        sum = carry + (f ? f->data : 0)
            + (s ? s->data : 0);
        // update carry for next calculation
        carry = (sum >= 10) ? 1 : 0;
        // update sum if it is greater than 10
        sum = sum % 10;
        // Create a new node with sum as data
        temp = newNode(sum);
        // if this is the f node then
        // set it as head of the resultant list
        if (res == NULL)
            res = temp;
        // If this is not the f
        // node then connect it to the rest.
        else
            prev->next = temp;
        // Set prev for next insertion
        prev = temp;
        // Move f and s
        // pointers to next nodes
        if (f)
            f = f->next;
        if (s)
            s = s->next;
    }
    if (carry > 0)
        temp->next = newNode(carry);
    // return head of the resultant list
    return res;
}
 
node* reverse_ll(node* head)
{
    if (head == NULL || head->next == NULL)
        return head;
    node* rest = reverse_ll(head->next);
    head->next->next = head;
 
    head->next = NULL;
 
    /* fix the head pointer */
    return rest;
}   
 
 
// A utility function to print a linked list
void printList(node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}
 
/* Driver code */
int main(void)
{
    node* res = NULL;
    node* f = NULL;
    node* s = NULL;
 
    // create f list 7->5->9->4->6
    insert(&f, 6);
    insert(&f, 5);
    insert(&f, 9);
    insert(&f, 5);
    insert(&f, 9);
    printf("First List is ");
    printList(f);
 
    // create s list 8->4
    insert(&s, 4);
    insert(&s, 9);
    cout << "s List is ";
    printList(s);
 
    // reverse_ll both the lists
    f = reverse_ll(f);
    s = reverse_ll(s);
    // Add the two lists
    res = addTwoLists(f, s);
 
    // reverse_ll the res to get the sum
    res = reverse_ll(res);
    cout << "Resultant list is ";
    printList(res);
 
    return 0;
}