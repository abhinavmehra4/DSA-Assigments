#include<iostream>
using namespace std;
void Display(int x[],int n )
{
    for(int i =0; i<n;i++)
    {
        cout<<x[i]<<" ";//outputing array values.
    }
}
void shift(int x[],int n)
{
    int last = x[n-1];
    for(int i=n-2;i>=0;i--)
    {
        x[i+1]=x[i];
    }
    x[0]=last;
    cout<<"The shifted array is \n";
    Display(x,n);
}

int main()
{
    int arr[] = {12,94,-4,45,6,12,98,-3,5,78,-1};
    int n = sizeof(arr)/sizeof(arr[0]);
    shift(arr,n);

    return 0;
}