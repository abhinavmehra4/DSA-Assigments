#include<iostream>
using namespace std;
int add(int f, int l)
{
    if (f>l)
        {
            int temp;
            temp=f;
            f=l;
            l=temp;
        }
int sum=0;
    for(int i=f;i<=l;i++)
    {
        sum=sum+i;
    }
    return sum;
}
int main()
{   int first, last;
    cout<<"Enter the first ";
    cin>>first;
    cout<<"Enter the last ";
    cin>>last;
        
cout<<"The sum of the number between first an last inclusive is "<<add(first,last);
    return 0;
}