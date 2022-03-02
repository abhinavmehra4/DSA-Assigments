#include<iostream>
using namespace std;

int fib(int n)
{
    if(n<=0)
    {
        cout<<"Invalid entry\n";
        return 0;
    }
    if(n==1)
        return 0;
    else if(n==2)
        return 1;
    else
        return fib(n-1)+fib(n-2);

}

int main()

{   cout<<"Enter number of terms for which you want the series\n";
int num;
    cin>>num;
    for(int i=1;i<=num;i++)
    {
      cout<<fib(i)<<" ";  
    }
    
    return 0;
}