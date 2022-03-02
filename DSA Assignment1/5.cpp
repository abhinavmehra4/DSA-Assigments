#include<iostream>
using namespace std;
int linearSearch(int x[],int n,int n1)
{
    for(int i=0;i<n;i++)
    {
        if(n1==x[i])
        {
            cout<<"Element found and is at index no. "<<i;
            return 1;
            break;
        }
    }                                              
    return 0;
}
int main()
{
    int arr[] = {12,78,11,90,119,43};
    int n = sizeof(arr)/sizeof(arr[0]);
    int e;
    cout<<"Enter the element you want to find \n";
    cin>>e;
    int check = linearSearch(arr,n,e);
    if(!check)
    cout<<"Element not found\n";
return 0;
}