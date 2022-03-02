#include<iostream> 
using namespace std;

class Node
{
public:
Node  *next; int data; Node(int x)
{
data = x; next  =  NULL;
}
};

Node  *pushFront(Node  *head,  int  x)
{
Node  *newD  =  new  Node(x);  //  creating  a  new  node
newD->next  =  head;	//  head  goes  after  the  new  node  created return  newD;	//  return  the  new  node
}
Node  *pushEnd(Node  *head,  int  x)
{
Node  *newD  =  new  Node(x);  //  new  node  created Node  *curr  =  head;
if (head == NULL) return  newD;
while  (head->next  !=  NULL)  //  reaching  the  end  of  the  list head  =  head->next;
head->next  =  newD;  //  adding  new  node  to  end  of  exiting  list return  curr;	//  returning  head  of  the  previous  list
}
Node  *popFront(Node  *head)
{
if (head == NULL) return  head;
Node  *temp  =  head;  //  fetching  the  head  of  the  list head  =  head->next;  //  head  moves  to  the  next  node cout  <<  "Popped  element  is:  "  <<  temp->data  <<  endl; delete  temp;  //  deleting  the  head  of  the  list
return  head;
}
Node *popEnd(Node *head)
{
if (head == NULL) // when no nodes exist return  head;
 return head;
else  if  (head->next  ==  NULL)  //  when  single  node  is  present
{
    delete  head; 
    return  NULL;
}
Node  *curr  =  head;
while  (curr->next  !=  NULL  &&  curr->next->next  !=  NULL)  //  going  to  the second  last  element  of  the  list
curr  =  curr->next;

cout  <<  "Popped  element  is:  "  <<  curr->next->data  <<  endl; delete  curr->next;  //  deleting  last  element
curr->next  =  NULL; return  head;
}
int main()
{
int ch, x; Node  *q  =  NULL;

ch  =  -1;
while (ch != 0)
{
cout  <<  "Enter  0  to  exit"  <<  endl;
cout  <<  "Enter  1  for  push  front"  <<  endl; cout  <<  "Enter  2  for  push  back"  <<  endl; cout  <<  "Enter  3  for  pop  front"  <<  endl; cout  <<  "Enter  4  for  pop  back"  <<  endl; cin >> ch;
switch  (ch)
{
case  1:
cout  <<  "Enter  element  to  be  pushed:  "; cin  >>  x;
q  =  pushFront(q,  x); break;
case  2:
cout  <<  "Enter  element  to  be  pushed:  "; cin  >>  x;
q  =  pushEnd(q,  x); break;
case  3:
q  =  popFront(q); break;
case  4:
q  =  popEnd(q); break;
default:
break;
}
}
return  0;
}
