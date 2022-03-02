#include<iostream>
#include<string.h>
using namespace std;
#define MAX 100

//these are globally declared as every function can use them
char stack[MAX]; //to store the whole postfix expression
char postfix[MAX];
int top=-1;//indicates the index of the topmost element of the stack;

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
float post_eval()
{
    int i,a,b;
    for( i=0;i<strlen(postfix);i++)
    {
        //because we are comparing the characters and not the numbers, we are
        //actually comparing the ASCII codes of 0-9
        if(postfix[i] >= '0' && postfix[i] <= '9')
        {
            push(postfix[i]-'0');
        }
        else
        {
            a=pop();
            b=pop();
            //we have to do b-a
            switch (postfix[i])
            {
            case '+':
                    push(b+a); break;
             case '*':
                    push(b*a); break;
             case '/':
                    push(b/a);break;
             case '-':
                    push(b-a);break;
             case '^':
                    push(b^a);break;
            }
        }
    }
    return pop();
}
int main()
{

    cout<<"Enter the postfix expression you want to evaluate\n";
    gets(postfix);
    float result;
    result = post_eval();
    cout<<endl;
    cout<<"The output of the postfix expression is\n"<<result;

    return 0;
}