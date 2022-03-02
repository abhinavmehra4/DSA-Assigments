#include<iostream>
using namespace std;
void Display(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}
void shift(int x[],int n)
{
    int last = x[n-1];
    for(int i=n-2;i>=0;i--)
    {
        x[i+1]=x[i];
    }
    x[0]=last;
}
void rotate(int arr[],int n,int x)
{
    int i = 1;
    while(i<=x)
    {
        shift(arr,n);
        i++;
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    //Display 
    Display(arr, n);    
    cout<<endl;
    int num;
    cout<<"Enter the number of times you want the array to get rotated\n";
    cin>>num;
    rotate(arr,n,num);

    cout<<"The rotated array is\n";
    Display(arr,n);


return 0;
}