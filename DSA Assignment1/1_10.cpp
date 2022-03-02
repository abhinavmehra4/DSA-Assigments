#include<iostream>
using namespace std;
int* merge(int x[],int y[],int arr3[],int n1,int n2,int n3)
{
    for(int i=0;i<n1;i++)
    {
        arr3[i]=x[i];
    }
    for(int i=n1,j=0;i<(n3);i++,j++)
    {
        arr3[i]=y[j];
    }
    return arr3;
}

int main()
{
    int arr1[]={88,109};
    int n1=sizeof(arr1)/sizeof(arr1[0]);
    int arr2[]={6,7,8,12,111,123591,12,7};
    int n2=sizeof(arr2)/sizeof(arr2[0]);
    int n3=n2+n1;
    int arr3[n3];
    int* merged_arr = merge(arr1,arr2,arr3,n1,n2,n3);
    cout<<"Merged array is \n";
    for(int i=0;i<n3;i++)
    {
        cout<<*(merged_arr+i)<<" ";
    }
    return 0;
}