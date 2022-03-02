#include<iostream>
#include<string.h>

using namespace std;

#define MAX 100
int top=-1;
char stack[MAX],expression[MAX],parenthesis[MAX];

void push(int data)
{
    if(top==MAX-1)
    {
        cout<<"Stack overflow\n";
        return;
    }
    top++;
    stack[top]=data;
}

int pop()
{
    if(top<0)
    {
        cout<<"Stack underflow\n";
        return 0;
    }
    else
    return stack[top--];
    
}

void valid_parenthesis(char exp[])
{
    for(int i=0;i<strlen(exp);i++)
    {
        char symbol = exp[i], next=exp[i+1];

        if(symbol=='['||symbol=='{'||symbol=='(')
        {
            push(symbol);
            cout<<symbol<<endl;
        }

        if(symbol==next)
        {   
            parenthesis[i++]=pop();

            //cout<<parenthesis[]<<endl;
            //parenthesis[top++]=next;
        }

        if(symbol==']'||symbol=='}'||symbol==')')
        {
            parenthesis[i++]=symbol;
    
            cout<<parenthesis[top]<<endl;
        }

    }

    
}

int main()
{

cout<<"enter the parenthesis expression\n";
gets(expression);
valid_parenthesis(expression);
cout<<endl<<"fuck off"<<endl;
// cout<<parenthesis[0]<<endl;
for(int i =0;i<strlen(parenthesis);i++)
    {
        cout<<parenthesis[i];
    }

return 0;
}

