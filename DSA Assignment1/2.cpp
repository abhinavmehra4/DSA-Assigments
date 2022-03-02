#include<iostream>
using namespace std;
int sum(int x[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+x[i];
    }
    return sum;
}
int maxIndex(int arr[], int n)
{
    int max = arr[0];
    int i;
    for (i = 1; i < n; i++)
        {  if (arr[i] > max)
           {max = arr[i];}
        }
    cout<<"Index of the maximum element of the array is "<<i<<endl;
    return max;
}
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
    cout<<"Sum of the elements of the array is "<<sum(arr,n)<<endl;
    int max=maxIndex(arr,n);
    cout<<"Maximum element of the array is "<<max<<endl;
    int e;
    cout<<"Enter the element you want to find \n";
    cin>>e;
    int check = linearSearch(arr,n,e);
    if(!check)
    cout<<"Element not found\n";
return 0;
}