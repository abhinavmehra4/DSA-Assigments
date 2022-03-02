#include<iostream>
using namespace std;

int maxIndex(int arr[], int n)
{
    int max = arr[0];
    int i;
    for (i = 1; i < n; i++)
        {
            if (arr[i] > max)
           {max = arr[i];}
        }
    cout<<"Index of the maximum element of the array is "<<i<<endl;
    return max;
}

int main()
{
    int arr[] = {45,6,12,98,-3,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int max=maxIndex(arr,n);
    cout<<"Maximum element of the array is "<<max;

    return 0;
}