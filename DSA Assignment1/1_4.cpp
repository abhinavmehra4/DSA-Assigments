#include<iostream>
using namespace std;
int main()
{
    int n,x;
    cout<<"Enter the integer ";
    cin>>n;

    if(n==1||n==0)
    {
        cout<<"Not a prime  number";
    }

    else{
        for(int i=2;i<=n/2;i++)
        {
            if(n%i==0)
            {
                x=0;
            }

        }
    }

    x?cout<<"Number is Prime":cout<<"number is not prime";

    return 0;
}