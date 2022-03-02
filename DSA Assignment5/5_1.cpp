#include<iostream>
using namespace std;

class Node{
	public:
		int key;
		Node* next; // pointer to keep track of address of the next node in the linked list
};

void push(Node** head_ref, int new_key)
{
	// we pass a reference to the head, so as to not change the position of the head
	//the function is designed in such a manner that the head remains at the first node.
	Node* new_node = new Node();
	new_node->key=new_key;
	new_node->next = *(head_ref);
	*(head_ref)=new_node;
}

void print(Node* n)
{
	while(n!=NULL)
	{
		cout<<n->key<<" ";
		n=n->next;
	}
}

bool search(Node* c, int s)
{
	Node* current =c;
	
	while(current!=NULL)
	{
		if(current->key==s)
		{
			return true;
		}
		current=current->next;
	}
	return false;
}

void delete_end(Node* n)
{
	Node* temp=n;
	while(temp->next->next!=NULL)
	//the while condition checks whether the two subsequent nodes have no NULL value
	{
		temp = temp->next;
	}
	//once we traverse till the second last element, change it's next pointer to NULLs
	temp->next=NULL;
}

void delete_middle(Node*n,int k)
{
	Node* temp=n;
	while(temp->next->key!=k)
	{
		temp=temp->next;
	}
	temp=temp->next->next;

    // for(Node* i=temp;temp->key!=k;i=i->next)
    // {
    //     if(i->next!=NULL) {
    //         i = i->next;
    //     }
    //     }

    //     temp->next = i->next->next;
}

void count_sum(Node* n)
{
    Node* temp = n;
    int count=0, sum=0;
    while(temp!=NULL)
    {
        count++;
        sum += temp->key;
        temp=temp->next;
    }
    cout<<"The number of nodes are "<<count<<endl<<"And the sum of the nodes are "<<sum<<endl;
}


// bool isSorted(Node* head)
// {
//     if(head==NULL)
//         return true;
//     //traversing the list till the last node
//     for(Node* i = head;i->next==NULL;i=i->next)
//         if(i->key<=i->next->key)
//             return false;
//         //we use the above condition because the elements enter the linked list in descending order.
//     return true;
// }

bool isSorted(Node *head)
{
    if (head == NULL)
        return true;
 
    // Traverse the list till last node and return
    // false if a node is smaller than or equal
    // its next.
    for (Node *t=head; t->next != NULL; t=t->next)
       if (t->key >= t->next->key)
            return false;
    return true;
}

void concat_ll(Node* n1, Node* n2)
{
    Node* temp1 = n1;
    Node* temp2 = n2;

    while(temp1->next!=NULL)
    {
        temp1 = temp1->next;
    }
    temp1->next = temp2;
    return;

}

void sort_ll(Node** head_ref)
{
    Node* current = *head_ref; // we are again passing a pointer ot a pointer.
    Node* index=NULL;
    int temp;

    if(current==NULL)
        return;
    else{

        while(current!=NULL)
        {
            index=current->next;//this points to the node next to the current.
            while(index!=NULL)
            {
                if(current->key>index->key)
                {
                    temp = current->key;
                    current->key=index->key;
                    index->key=temp;
                }
                index=index->next;
            }
            current=current->next;
        }
    }       
}

void merge_ll(Node** head_ref1,Node** head_ref2)
{
    Node* current1 = *head_ref1;
    Node* current2 = *head_ref2;

    
    //sort_ll(&current2);

    concat_ll(current1,current2);
    sort_ll(&current1);
    
}

void reverse(Node** n)
    {
        // Initialize current, previous and
        // next pointers
        Node* current = *n;
        Node *prev = NULL, *next = NULL;
  
        while (current != NULL) {
            // Store next
            next = current->next;
  
            // Reverse current node's pointer
            current->next = prev;
  
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        *n = prev;
    }

int main()
{
	Node* head = NULL;
	push(&head,6);
	push(&head,5);
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);	
	
    //displaying elements
	print(head);
	
    cout<<endl;

    //count and sum the nodes sof a linked list
    count_sum(head);

	cout<<endl<<"Enter the element you want to search\n";
	int num;
	cin>>num;

    //deleting a code
	cout<<endl<<"from where do you want to delete the node\n 1. Beginning\n 2. End\n";
	int option;
	cin>>option;
	switch(option)
	{
		case 1:
			cout<<endl<<"Linked list after deleting the first element is \n";
			head=head->next;
			print(head);
			break;
		
		default:
			delete_end(head);
			print(head);
				break;
	}
	
    //searching for a key element in a linked list
	if(search(head,num))
		cout<<"Element is present\n";
	else
		cout<<"Element is absent\n";
	
    //concatenating 2 linked lists
    Node* head1 = NULL;
	push(&head1,12);
	push(&head1,11);
	push(&head1,10);
	push(&head1,9);
	push(&head1,8);
	push(&head1,7);

    print(head1);
    cout<<endl;
    concat_ll(head,head1);

    cout<<endl<<"Hello world\n";
    print(head);

    //checking if linked list is sorted
    cout<<endl;
    cout<<"Hello world\n";

    Node* head2 = NULL;
    // push(&head2,7);
	// push(&head2,6);
	// push(&head2,5);
	// push(&head2,4);
	// push(&head2,3);
	// push(&head2,2);
    push(&head2,7);
	push(&head2,6);
	push(&head2,55);
	push(&head2,4);
	push(&head2,3);
	push(&head2,22);

    print(head2);
    cout<<endl;

    if(isSorted(head2))
    cout<<"String is sorted\n";
    else
    cout<<"String is not sorted\n";

    //sorting an array

    Node* head3 = NULL;
    push(&head3,2);
	push(&head3,1);
	push(&head3,110);
	push(&head3,19);
	push(&head3,8);
	push(&head3,77);

    print(head3);

    sort_ll(&head3);

    cout<<endl;

    print(head3);

    //merging a linked list.

    Node* head4 = NULL;
    push(&head4,2);
	push(&head4,1);
	push(&head4,11);
	push(&head4,19);
	push(&head4,58);
	push(&head4,79);

    cout<<endl<<"The linked list is\n";
    print(head4);

    Node* head5 = NULL;
    push(&head5,3);
	push(&head5,13);
	push(&head5,19);
	push(&head5,5);
	push(&head5,98);
	push(&head5,69);

    cout<<endl<<"The linked list is\n";
    print(head5);

    cout<<endl<<"The merged array is\n";

    merge_ll(&head4,&head5);

    print(head4);

    // reversing a linked list

    reverse(&head4);
    cout<<endl;
    print(head4);

	return 0;
}
