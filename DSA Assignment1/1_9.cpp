#include<iostream>
using namespace std;
void Display(int x[],int n )
{
    for(int i =0; i<n;i++)
    {
        cout<<x[i]<<" ";//outputing array values.
    }
}
int* sort(int x[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(x[j]>x[j+1])
            {
                int temp;
                temp=x[j];
                x[j]=x[j+1];
                x[j+1]=temp;
            }
        }
    }
    return x;
}
int removeDuplicates(int arr[], int n)
{
    if (n==0 || n==1)
        return n;
    
    int temp[n];
    int j = 0;
    for (int i=0; i<n-1; i++)
        {if (arr[i] != arr[i+1])
            temp[j++] = arr[i];
        }
    temp[j++] = arr[n-1];

    for (int i=0; i<j; i++)
       { arr[i] = temp[i];}
 
    return j;
}
int main()
{
    int arr[] = {11,8,8,2,3,12,1,1,8,8,8,8,8,1,1,19,21,2,2,11,11,3,3,19,21};
    int n = sizeof(arr)/sizeof(arr[0]);
    int* sorted_arr = sort(arr,n);
    n = removeDuplicates(sorted_arr,n);
    
    for(int i=0;i<n;i++)
    {
        cout<<*(sorted_arr+i)<<" ";
    }
 
    return 0;
}