//very basic type of bubble sort algorithm.
#include<iostream>
using namespace std;
void bubbleSort(int arr[],int n)
{

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
int main()
{
    int a[] = {-2,45,0,11,-9};
    int n = 5;// a way to find the size of the array.
    cout<<n<<endl;

    for(int i=0; i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl<<"The sorted order of the array is "<<endl;

    bubbleSort(a,n);

    for(int i=0; i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
